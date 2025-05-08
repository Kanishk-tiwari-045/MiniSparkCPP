#ifndef LOGISTIC_REGRESSION_H
#define LOGISTIC_REGRESSION_H

#include "RDD.h"
#include "MappedRDD.h"
#include <vector>
#include <string>

struct DataPoint {
    std::vector<double> features;
    double label;

    DataPoint(const std::vector<double>& f, double l)
        : features(f), label(l) {}
};

class LogisticRegression {
public:
    static DataPoint parsePoint(const std::string& line);

    static double sigmoid(double z);

    static std::vector<double> computeGradient(const DataPoint& point, const std::vector<double>& weights);

    static std::vector<double> addGradients(const std::vector<double>& g1, const std::vector<double>& g2);

    static std::vector<double> updateWeights(const std::vector<double>& weights, const std::vector<double>& gradient, double learningRate);

    static std::vector<double> run(std::shared_ptr<RDD<std::string>> dataRDD, int iterations, double learningRate);
};

#endif // LOGISTIC_REGRESSION_H
