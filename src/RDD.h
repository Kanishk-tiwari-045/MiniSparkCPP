#ifndef RDD_H
#define RDD_H

#include <vector>
#include <memory>
#include <functional>
#include <stdexcept>
#include <iostream>
#include "Partition.h"

// Forward declarations of our concrete RDD types:
template<typename T, typename U> class MappedRDD;
template<typename T> class FilteredRDD;
template<typename T, typename U> class FlatMappedRDD;

// Base class to hold partitions and allow heterogeneous dependencies.
class RDDBase {
public:
  std::vector<Partition> partitions;
  virtual ~RDDBase() = default;
};

// Templated abstract RDD class
template<typename T>
class RDD : public RDDBase, public std::enable_shared_from_this<RDD<T>> {
public:
  using Ptr = std::shared_ptr<RDD<T>>;

  // List of parent RDDs (lineage)
  std::vector<std::shared_ptr<RDDBase>> dependencies;

  // Constructor takes partition definitions
  RDD(const std::vector<Partition>& parts) {
    this->partitions = parts;
  }

  // Subclasses must implement compute for one partition
  virtual std::vector<T> compute(const Partition& part) = 0;

  // Action: collects all partitions, with retry logic
  std::vector<T> collect() {
    int skippedCount = 0;
    std::vector<T> output;

    for (auto& part : this->partitions) {
      std::vector<T> partResult;
      bool success = false;

      // Retry up to 3 times
      for (int attempt = 1; attempt <= 3; ++attempt) {
        try {
          partResult = compute(part);
          success = true;
          break;
        } catch (const std::exception& e) {
          std::cerr << "Partition " << part.index
                    << " failed (Attempt " << attempt << "/3), recomputing...\n";
        }
      }

      if (!success) {
        skippedCount++;
        std::cerr << "Partition " << part.index
                  << " failed after 3 attempts, skipping.\n";
      } else {
        // Append successful results
        output.insert(output.end(), partResult.begin(), partResult.end());
      }
    }

    // If more than half the partitions failed, abort
    if (skippedCount > static_cast<int>(this->partitions.size()) / 2) {
      throw std::runtime_error("Too many partitions skipped; aborting.");
    }

    return output;
  }

  // Transformations
  template<typename U>
  std::shared_ptr<RDD<U>> map(std::function<U(const T&)> f) {
    auto prevPtr = this->shared_from_this();
    auto r = std::make_shared<MappedRDD<T, U>>(prevPtr, f);
    return r;
  }

  std::shared_ptr<RDD<T>> filter(std::function<bool(const T&)> f) {
    auto prevPtr = this->shared_from_this();
    auto r = std::make_shared<FilteredRDD<T>>(prevPtr, f);
    return r;
  }

  template<typename U>
  std::shared_ptr<RDD<U>> flatMap(std::function<std::vector<U>(const T&)> f) {
    auto prevPtr = this->shared_from_this();
    auto r = std::make_shared<FlatMappedRDD<T, U>>(prevPtr, f);
    return r;
  }
};

#endif // RDD_H
