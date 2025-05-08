#include "LogisticRegression.h"
#include <sstream>
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <algorithm>

// Parse a CSV line into a DataPoint
DataPoint LogisticRegression::parsePoint(const std::string& line) {
    std::vector<double> features;
    std::string token;
    std::stringstream ss(line);
    std::vector<std::string> tokens;

    while (std::getline(ss, token, ',')) {
        tokens.push_back(token);
    }

    if (tokens.size() < 2) {
        throw std::invalid_argument("Line too short for valid DataPoint: " + line);
    }

    for (size_t i = 0; i < tokens.size() - 1; ++i) {
        features.push_back(std::stod(tokens[i]));
    }

    double label = std::stod(tokens.back());
    return DataPoint(features, label);
}

// Sigmoid function
double LogisticRegression::sigmoid(double z) {
    return 1.0 / (1.0 + std::exp(-z));
}

// Compute gradient for a single data point
std::vector<double> LogisticRegression::computeGradient(const DataPoint& point, const std::vector<double>& weights) {
    double dot = 0.0;
    for (size_t i = 0; i < point.features.size(); ++i) {
        dot += point.features[i] * weights[i];
    }

    double prediction = sigmoid(dot);
    std::vector<double> gradient(point.features.size());

    for (size_t i = 0; i < gradient.size(); ++i) {
        gradient[i] = (prediction - point.label) * point.features[i];
    }

    return gradient;
}

// Sum two gradients
std::vector<double> LogisticRegression::addGradients(const std::vector<double>& g1, const std::vector<double>& g2) {
    std::vector<double> sum(g1.size());
    for (size_t i = 0; i < g1.size(); ++i) {
        sum[i] = g1[i] + g2[i];
    }
    return sum;
}

// Apply weight update
std::vector<double> LogisticRegression::updateWeights(const std::vector<double>& weights, const std::vector<double>& gradient, double learningRate) {
    std::vector<double> updated(weights.size());
    for (size_t i = 0; i < weights.size(); ++i) {
        updated[i] = weights[i] - learningRate * gradient[i];
    }
    return updated;
}

// Main run loop
std::vector<double> LogisticRegression::run(std::shared_ptr<RDD<std::string>> dataRDD, int iterations, double learningRate) {
    auto pointsRDD = std::make_shared<MappedRDD<std::string, DataPoint>>(dataRDD, parsePoint);

    std::vector<DataPoint> points = pointsRDD->collect();
    if (points.empty()) {
        throw std::runtime_error("No data points available.");
    }

    std::vector<double> weights(points[0].features.size(), 0.0);

    for (int i = 1; i <= iterations; ++i) {
        auto gradientRDD = std::make_shared<MappedRDD<DataPoint, std::vector<double>>>(pointsRDD,
            [&weights](const DataPoint& point) {
                return computeGradient(point, weights);
            });

        std::vector<std::vector<double>> gradients = gradientRDD->collect();
        std::vector<double> totalGrad = gradients[0];
        for (size_t j = 1; j < gradients.size(); ++j) {
            totalGrad = addGradients(totalGrad, gradients[j]);
        }

        weights = updateWeights(weights, totalGrad, learningRate);

        std::cout << "Iteration " << i << ", updated weights: ";
        for (const auto& w : weights) std::cout << w << " ";
        std::cout << std::endl;
    }

    return weights;
}
