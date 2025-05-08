#ifndef FLATMAPPEDRDD_H
#define FLATMAPPEDRDD_H

#include "RDD.h"
#include <functional>
#include <vector>
#include <memory>

template<typename T, typename U>
class FlatMappedRDD : public RDD<U> {
public:
  using Func = std::function<std::vector<U>(const T&)>;

  FlatMappedRDD(std::shared_ptr<RDD<T>> prev, Func f)
    : RDD<U>(prev->partitions), prevRDD(prev), flatMapFunc(f)
  {
    this->dependencies.push_back(prevRDD);
  }

  std::vector<U> compute(const Partition& part) override {
    std::vector<T> input = prevRDD->compute(part);
    std::vector<U> output;
    for (const auto& item : input) {
      std::vector<U> expanded = flatMapFunc(item);
      output.insert(output.end(), expanded.begin(), expanded.end());
    }
    return output;
  }

private:
  std::shared_ptr<RDD<T>> prevRDD;
  Func flatMapFunc;
};

#endif // FLATMAPPEDRDD_H
