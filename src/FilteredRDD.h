#ifndef FILTEREDRDD_H
#define FILTEREDRDD_H

#include "RDD.h"
#include <functional>
#include <vector>
#include <memory>

template<typename T>
class FilteredRDD : public RDD<T> {
public:
  using Predicate = std::function<bool(const T&)>;

  // Constructor: takes shared_ptr to parent RDD and filter function
  FilteredRDD(std::shared_ptr<RDD<T>> prev, Predicate f)
    : RDD<T>(prev->partitions), prevRDD(prev), predicate(f)
  {
    this->dependencies.push_back(prevRDD);
  }

  // Compute method applies the filter function to the parent data
  std::vector<T> compute(const Partition& part) override {
    std::vector<T> input = prevRDD->compute(part);
    std::vector<T> output;
    for (const auto& item : input) {
      if (predicate(item)) {
        output.push_back(item);
      }
    }
    return output;
  }

private:
  std::shared_ptr<RDD<T>> prevRDD;
  Predicate predicate;
};

#endif // FILTEREDRDD_H
