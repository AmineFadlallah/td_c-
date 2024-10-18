#ifndef SEARCHING_ALGORITHM_H
#define SEARCHING_ALGORITHM_H

#include <iostream>
#include <vector>

class SearchingAlgorithm{
	protected:
		int numberComparaisons;
		static int totalComparaisons;
		static int totalSearch;
		static double averageComparaisons;
	public:
		SearchingAlgorithm();
		virtual int search(const std::vector<int>& vect, int value) = 0;
		void displaySearchResults(std::ostream& os, int result, int value);
};

#endif
