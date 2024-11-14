#ifndef SIN_WAVE_GENERATOR_H
#define SIN_WAVE_GENERATOR_H

#include "TimeSeriesGenerator.h"
#include <vector>

class SinWaveGenerator : public TimeSeriesGenerator {
private:
    double amplitude; // Amplitude of the sine wave
    double frequency; // Frequency of the sine wave
    double phase;     // Initial phase of the sine wave

public:
    // Constructors
    SinWaveGenerator();
    SinWaveGenerator(int seed, double amplitude, double frequency, double phase);

    // Generate a sinusoidal time series
    vector<double> generateTimeSeries(int size) override;
};

#endif
