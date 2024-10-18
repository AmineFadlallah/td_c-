#include "SearchingAlgorithm.h"
#include "LinearSearch.h"
#include "JumpSearch.h"
#include "BinarySearch.h"
#include <iostream>
#include <string>

int main(){
    int target = 9;
    std::vector<int> data = {0, 2, 8, 9, 10, 11, 13, 15, 16, 17};


    LinearSearch linear;
    int result = linear.search(data, target);
    linear.displaySearchResults(std::cout, result, target);

    JumpSearch jump;
    result = jump.search(data, target);
    jump.displaySearchResults(std::cout, result, target);

    BinarySearch binary;
    result = binary.search(data, target);
    binary.displaySearchResults(std::cout, result, target);


}
