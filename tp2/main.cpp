#include "TimeSeriesGenerator.h"
#include "GaussianGenerator.h"
#include <iostream>
using namespace std;

int main(){
	GaussianGenerator g1 (42,0.0,1.0);
	TimeSeriesGenerator::printTimeSeries(g1.generateTimeSeries(10));
	return 0;
}
