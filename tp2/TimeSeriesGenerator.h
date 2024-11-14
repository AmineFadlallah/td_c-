#ifndef TIME_SERIES_GENERATOR_H
#define TIME_SERIES_GENERATOR_H
#include <string>
#include <vector>
using namespace std;
class TimeSeriesGenerator{
protected:
	int seed;
public:
	TimeSeriesGenerator();
	TimeSeriesGenerator(int seed);
	virtual vector<double> generateTimeSeries(int size) = 0;
	static void printTimeSeries(vector<double> serie);
};

#endif
