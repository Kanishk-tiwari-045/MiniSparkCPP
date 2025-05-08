# MiniSparkCPP — Workflow

## Objective

The **MiniSparkCPP project** is a C++ implementation of a minimal distributed computing framework inspired by **Apache Spark**.
It focuses on:

* **Resilient Distributed Datasets (RDDs)**
* **Fault-tolerant in-memory computation**
* **Iterative algorithms (Logistic Regression, PageRank)**
* **Abstractions like map, filter, flatMap with lineage tracking**

The project demonstrates how big data systems like Spark achieve scalability, fault tolerance, and parallelism — all written in clean modern C++.

## High-Level Workflow

1. **Start the app (MiniSparkApp.cpp)**
   → Accepts CLI input:

   ```bash
   ./MiniSparkCPP <algorithm> <datafile> [iterations]
   ```

   → Example:

   ```bash
   ./MiniSparkCPP pagerank pages.txt 10
   ./MiniSparkCPP logistic logistic.txt 20
   ```

2. **Load input file (FileRDD)**
   → Reads text file, splits into partitions, simulates random failures.

3. **Transform data (MappedRDD, FilteredRDD, FlatMappedRDD)**
   → Supports functional-style operations like:

   * map
   * filter
   * flatMap

4. **Run iterative algorithms**

   * Logistic Regression:

     * Parses lines → gradients → updates weights over iterations.
   * PageRank:

     * Builds page graph → distributes rank → applies damping → updates over iterations.

5. **Handle failures with fault tolerance**
   → Retries failed partitions up to 3 times using lineage recomputation.
   → Logs partition failures, skips unrecoverable ones.

6. **Collect and print results**
   → Outputs final weights or PageRank scores.

## 💥 Main Components

| Component            | Purpose                                                       |
| -------------------- | ------------------------------------------------------------- |
| `Partition.h`        | Defines partition metadata (`index`)                          |
| `RDD.h`              | Abstract RDD class with `map`, `filter`, `flatMap`, `collect` |
| `MappedRDD.h`        | Transforms elements with `map`                                |
| `FilteredRDD.h`      | Filters elements with `filter`                                |
| `FlatMappedRDD.h`    | Flattens elements with `flatMap`                              |
| `FileRDD.h/.cpp`     | Loads data from file, partitions it                           |
| `LogisticRegression` | Runs iterative gradient descent                               |
| `PageRank`           | Runs iterative rank computation over pages                    |
| `MiniSparkApp.cpp`   | CLI runner to trigger algorithms                              |

## 🚀 Example Input Files

* **logistic.txt**

  ```
  0.5,1.2,3.4,1.0
  2.1,0.4,1.5,0.0
  1.3,2.2,0.9,1.0
  ```

* **pages.txt**

  ```
  pageA,pageB pageC
  pageB,pageD
  pageC,pageA
  pageD,pageA pageC
  ```

## 📦 GitHub README

```markdown
# MiniSparkCPP

A minimal Spark-like distributed computing framework in C++.

✅ Implements fault-tolerant Resilient Distributed Datasets (RDDs)  
✅ Supports `map`, `filter`, `flatMap`, and `collect`  
✅ Runs iterative algorithms: Logistic Regression, PageRank  
✅ Demonstrates lineage tracking and recomputation on failures

## Build

```bash
cmake -S . -B build
cmake --build build
```

## Run

```bash
./build/MiniSparkCPP <algorithm> <datafile> [iterations]
```

Example:

```bash
./build/MiniSparkCPP logistic logistic.txt 10
./build/MiniSparkCPP pagerank pages.txt 10
```

## Input Formats

* **Logistic Regression (`logistic.txt`)**

  ```
  feature1,feature2,feature3,label
  ```

* **PageRank (`pages.txt`)**

  ```
  page,neighbor1 neighbor2 neighbor3
  ```

## Features

* Fault tolerance: retries failed partitions up to 3 times
* Lineage tracking: recomputes partitions on failure
* Abstraction: generic RDD API with transformations + actions
* Algorithms: Logistic Regression, PageRank
