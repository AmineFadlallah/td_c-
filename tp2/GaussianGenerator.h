#ifndef GAUSSIANGENERATOR_H
#define GAUSSIANGENERATOR_H

#include "TimeSeriesGenerator.h"
#include <vector>

class GaussianGenerator : public TimeSeriesGenerator {
private:
    double mean;
    double stddev;
public:
    GaussianGenerator(int seedValue, double meanValue, double stddevValue);
    std::vector<double> generateTimeSeries(int size) override;
};

#endif
