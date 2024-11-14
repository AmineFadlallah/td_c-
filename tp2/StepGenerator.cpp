#include "StepGenerator.h"
#include <random>

StepGenerator::StepGenerator() : TimeSeriesGenerator() {}

StepGenerator::StepGenerator(int seed) : TimeSeriesGenerator(seed) {}

vector<double> StepGenerator::generateTimeSeries(int size) {
    vector<double> series;
    series.reserve(size);

    std::default_random_engine engine(seed);
    std::uniform_int_distribution<int> valueDist(0, 100);
    std::uniform_real_distribution<double> probDist(0.0, 1.0);

    double previousValue = 0;
    series.push_back(previousValue);

    for (int i = 1; i < size; ++i) {
        if (probDist(engine) < 0.5) {
            previousValue = valueDist(engine);
        }
        series.push_back(previousValue); 
    }

    return series;
}

