#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include "SearchingAlgorithm.h"

class BinarySearch : public SearchingAlgorithm{
    public:
	    int search(const std::vector<int>& data, int value) override;
};
#endif
