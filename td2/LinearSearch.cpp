#include "LinearSearch.h"

int LinearSearch ::search(const std ::vector<int>& data, int value){
    numberComparaisons = 0;
    for (int i = 0; i < data.size(); i++){
        numberComparaisons++;
        if (data[i]== value){
            return i;
        }
    }
    return -1;
}
