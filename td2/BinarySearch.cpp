#include "BinarySearch.h"

int BinarySearch::search(const std::vector<int>& data, int value) {
    numberComparaisons = 0;
    int right = data.size() - 1;
    int left = 0;
    while (left <= right) {
        numberComparaisons++;
        int mid = left + (right - left) / 2;
        if (data[mid] == value) { return mid; }
        if (data[mid] < value) {
            left = mid + 1; 
            right = mid - 1; 
        }
    }
    return -1;
}
