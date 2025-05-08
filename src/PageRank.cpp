#include "PageRank.h"
#include <sstream>
#include <iostream>
#include <set>
#include <algorithm>
#include <numeric>

using namespace std;

std::map<std::string, double> PageRank::run(std::shared_ptr<RDD<std::string>> linksRDD,
                                            int iterations,
                                            double dampingFactor) {
    using LinkPair = std::pair<std::string, std::vector<std::string>>;

    // Step 1: Parse lines to (page, neighbors)
    auto parsedRDD = std::make_shared<MappedRDD<std::string, LinkPair>>(
        linksRDD, [](const std::string& line) -> LinkPair {
            std::stringstream ss(line);
            std::string page, neighborsPart;
            getline(ss, page, ',');
            getline(ss, neighborsPart);

            std::vector<std::string> neighbors;
            std::stringstream nss(neighborsPart);
            std::string neighbor;
            while (nss >> neighbor) {
                neighbors.push_back(neighbor);
            }

            return { page, neighbors };
        });

    // Step 2: Initialize all page ranks to 1.0
    std::vector<LinkPair> linkData = parsedRDD->collect();
    std::set<std::string> pages;
    for (const auto& [page, _] : linkData) {
        pages.insert(page);
    }

    std::map<std::string, double> ranks;
    for (const auto& page : pages) {
        ranks[page] = 1.0;
    }

    // Step 3: Iterative updates
    for (int i = 1; i <= iterations; ++i) {
        // Step 3.1: Compute contributions
        auto contribRDD = std::make_shared<FlatMappedRDD<LinkPair, std::pair<std::string, double>>>(
            parsedRDD,
            [&ranks](const LinkPair& pair) -> std::vector<std::pair<std::string, double>> {
                const std::string& page = pair.first;
                const std::vector<std::string>& neighbors = pair.second;

                double rank = ranks.count(page) ? ranks[page] : 1.0;
                double contrib = neighbors.empty() ? 0.0 : rank / neighbors.size();

                std::vector<std::pair<std::string, double>> result;
                for (const auto& neighbor : neighbors) {
                    result.emplace_back(neighbor, contrib);
                }
                return result;
            });

        // Step 3.2: Collect and group by key
        std::vector<std::pair<std::string, double>> allContribs = contribRDD->collect();

        std::map<std::string, double> sumContribs;
        for (const auto& [page, contrib] : allContribs) {
            sumContribs[page] += contrib;
        }

        // Step 3.3: Apply damping factor
        std::map<std::string, double> newRanks;
        for (const auto& page : pages) {
            double sum = sumContribs.count(page) ? sumContribs[page] : 0.0;
            newRanks[page] = (1.0 - dampingFactor) + dampingFactor * sum;
        }

        // Step 3.4: Print ranks
        std::cout << "Iteration " << i << ", PageRank: ";
        for (const auto& [page, rank] : newRanks) {
            std::cout << page << "=" << rank << "  ";
        }
        std::cout << "\n";

        // Update ranks for next iteration
        ranks = newRanks;
    }

    return ranks;
}
