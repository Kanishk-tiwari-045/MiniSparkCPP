#include "FileRDD.h"
#include <random>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <cmath>

FileRDD::FileRDD(const std::string& filePath, int numPartitions)
  : RDD<std::string>([&]() {
      std::vector<Partition> parts;
      for (int i = 0; i < numPartitions; ++i) {
        parts.emplace_back(i);
      }
      return parts;
    }())
{
  // Read all lines from file into memory
  std::ifstream file(filePath);
  if (!file.is_open()) {
    throw std::runtime_error("Unable to open file: " + filePath);
  }

  std::string line;
  while (std::getline(file, line)) {
    lines.push_back(line);
  }
  file.close();

  // Determine size of each partition
  partitionSize = std::ceil(static_cast<double>(lines.size()) / numPartitions);
}

std::vector<std::string> FileRDD::compute(const Partition& part) {
    // Simulate failure in 20% of calls
    static std::random_device rd;
    static std::mt19937 rng(rd());
    static std::uniform_int_distribution<> dist(0, 9);
  
    if (dist(rng) < 2) {
      throw std::runtime_error("Simulated failure in FileRDD");
    }
  
    int start = part.index * partitionSize;
    int end = std::min(start + partitionSize, static_cast<int>(lines.size()));
  
    std::vector<std::string> partitionData;
    for (int i = start; i < end; ++i) {
      partitionData.push_back(lines[i]);
    }
  
    return partitionData;
  }
  