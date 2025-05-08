#ifndef FILERDD_H
#define FILERDD_H

#include "RDD.h"
#include <string>
#include <vector>
#include <memory>

class FileRDD : public RDD<std::string> {
public:
  FileRDD(const std::string& filePath, int numPartitions);
  std::vector<std::string> compute(const Partition& part) override;

private:
  std::vector<std::string> lines;
  int partitionSize;
};

#endif // FILERDD_H
