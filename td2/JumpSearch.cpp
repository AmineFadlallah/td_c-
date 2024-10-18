#include "JumpSearch.h"
#include <cmath>


int JumpSearch::search(const std::vector<int>& data, int value) {
    int prev = 0;
    int n = data.size();
    int step = std::sqrt(n);
    numberComparaisons = 0;
    
    while (data[std::min(step, n) - 1] < value) {
        numberComparaisons++;
        prev = step;
        step += std::sqrt(n);
        if (prev >= n) {
            return -1; 
        }
    }
    for (int i = prev; i < std::min(step, n); i++) {
        numberComparaisons++;
        if (data[i] == value) {
            return i; 
        }
    }
    return -1;
} 
