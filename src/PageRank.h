#ifndef PAGERANK_H
#define PAGERANK_H

#include "RDD.h"
#include "MappedRDD.h"
#include "FlatMappedRDD.h"
#include <string>
#include <vector>
#include <map>
#include <memory>

class PageRank {
public:
    static std::map<std::string, double> run(std::shared_ptr<RDD<std::string>> linksRDD,
                                             int iterations,
                                             double dampingFactor = 0.85);
};

#endif // PAGERANK_H
