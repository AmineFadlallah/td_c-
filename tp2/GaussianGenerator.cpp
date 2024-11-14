#include "GaussianGenerator.h"
#include <cmath>
#include <cstdlib>
#include <vector>

GaussianGenerator::GaussianGenerator(int seedValue, double meanValue, double stddevValue)
    : TimeSeriesGenerator(seedValue), mean(meanValue), stddev(stddevValue) {
    srand(seed);
}
std::vector<double> GaussianGenerator::generateTimeSeries(int size) {
    std::vector<double> series;
    for (int i = 0; i < size; ++i) {
        double u1 = static_cast<double>(rand()) / RAND_MAX;
        double u2 = static_cast<double>(rand()) / RAND_MAX;
        double z0 = sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);
        double gaussianValue = mean + z0 * stddev;
        series.push_back(gaussianValue);
    }
    return series;
}
