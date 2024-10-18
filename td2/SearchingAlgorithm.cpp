#include <iostream>
#include <string>
#include "SearchingAlgorithm.h"

int SearchingAlgorithm::totalComparaisons = 0;
int SearchingAlgorithm::totalSearch = 0;
double SearchingAlgorithm::averageComparaisons = 0.0;

SearchingAlgorithm::SearchingAlgorithm() : numberComparaisons(0){};

void SearchingAlgorithm::displaySearchResults(std::ostream& os, int result, int value) {
    totalComparaisons += numberComparaisons;
    totalSearch++;
    if (result != -1) {
        os << "indice: " << result << " nombre comparaisons: \n" << numberComparaisons;
    } else {
        os << "not found " ;
    }
    os << "total comparaisons: " << totalComparaisons << "\n";
    os << "total recherches: " << totalSearch << "\n";
    os << "comparaisons moyennes: " << averageComparaisons << "\n";
}
