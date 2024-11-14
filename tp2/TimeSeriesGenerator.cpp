#include "TimeSeriesGenerator.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

TimeSeriesGenerator::TimeSeriesGenerator() : seed(1) {}
TimeSeriesGenerator::TimeSeriesGenerator(int seed) : seed(seed) {}

void TimeSeriesGenerator::printTimeSeries(const vector<double> serie){
	for(double v : serie){
		cout <<v<<"|";
	}
	cout << endl;
}
