#ifndef MAPPEDRDD_H
#define MAPPEDRDD_H

#include "RDD.h"
#include <random>
#include <chrono>
#include <stdexcept>

// Forward‐declare to satisfy base class template
template<typename T, typename U>
class MappedRDD;

// Definition of MappedRDD
template<typename T, typename U>
class MappedRDD : public RDD<U> {
public:
  using Func = std::function<U(const T&)>;

  // Constructor: takes shared_ptr to parent RDD and mapping function
  MappedRDD(std::shared_ptr<RDD<T>> prev, Func f)
    : RDD<U>(prev->partitions), prevRDD(prev), func(f),
      // Random engine seeded from high‐res clock
      rng(static_cast<unsigned>(
          std::chrono::high_resolution_clock::now().time_since_epoch().count())),
      dist(0, 9)
  {
    // Record lineage for fault tolerance
    this->dependencies.push_back(prevRDD);
  }

  // Override compute: apply failure simulation, then map over parent data
  std::vector<U> compute(const Partition& part) override {
    // 20% chance to simulate a transient failure
    if (dist(rng) < 2) {
      throw std::runtime_error("Simulated failure in MappedRDD");
    }
    // Get parent partition data
    auto parentData = prevRDD->compute(part);
    // Apply map function
    std::vector<U> result;
    result.reserve(parentData.size());
    for (auto& elem : parentData) {
      result.push_back(func(elem));
    }
    return result;
  }

private:
  std::shared_ptr<RDD<T>> prevRDD;
  Func func;
  // RNG for failure simulation
  std::mt19937 rng;
  std::uniform_int_distribution<> dist;
};

#endif // MAPPEDRDD_H
