#include <iostream>
#include <string>
#include <memory>
#include "FileRDD.h"
#include "LogisticRegression.h"
#include "PageRank.h"

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: ./MiniSparkCPP <algorithm> <datafile> [iterations]\n";
        std::cerr << "Example: ./MiniSparkCPP pagerank data.txt 10\n";
        std::cerr << "         ./MiniSparkCPP logistic data.csv 20\n";
        return 1;
    }

    std::string algorithm = argv[1];
    std::string filename = argv[2];
    int iterations = (argc >= 4) ? std::stoi(argv[3]) : 10;
    int numPartitions = 4;

    try {
        std::shared_ptr<RDD<std::string>> fileRDD = std::make_shared<FileRDD>(filename, numPartitions);

        if (algorithm == "pagerank") {
            std::map<std::string, double> ranks = PageRank::run(fileRDD, iterations);
            std::cout << "\nFinal PageRank:\n";
            for (const auto& [page, rank] : ranks) {
                std::cout << page << ": " << rank << "\n";
            }
        } else if (algorithm == "logistic") {
            double learningRate = 0.1;
            std::vector<double> weights = LogisticRegression::run(fileRDD, iterations, learningRate);
            std::cout << "\nFinal Weights:\n";
            for (double w : weights) {
                std::cout << w << " ";
            }
            std::cout << "\n";
        } else {
            std::cerr << "Unknown algorithm: " << algorithm << "\n";
            return 1;
        }
    } catch (const std::exception& ex) {
        std::cerr << "Error running MiniSpark: " << ex.what() << "\n";
        return 1;
    }

    return 0;
}
