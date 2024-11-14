#ifndef STEP_GENERATOR_H
#define STEP_GENERATOR_H

#include "TimeSeriesGenerator.h"
#include <vector>

class StepGenerator : public TimeSeriesGenerator {
public:
    StepGenerator();
    StepGenerator(int seed);
    vector<double> generateTimeSeries(int size) override;
};

#endif
