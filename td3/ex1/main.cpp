#include <iostream>
#include <vector>
#include <map>
#include <algorithm> // pour std::sort

using namespace std;

bool isInVect(const vector<int>& vect, int value){
	for(int i=0; i<vect.size(); i++){
		if(value==vect[i]){
			return 1;}
	}
	return 0;
}

void countFrequencyBruteForce(const vector<int>& numbers) {
     vector<int> parcourus = {};
    // Parcourir chaque élément
    	for (int i = 0; i < numbers.size(); i++) {
		if(isInVect(parcourus,numbers[i])==0){
        		int count = 1;
        		for (int j = i + 1; j < numbers.size(); j++) {
            			if (numbers[i] == numbers[j]) {
                			count++;
            			}
	    			parcourus.push_back(numbers[i]) ;
        		}
        		cout << numbers[i] << " : " << count << " fois" << endl;
		}
    	}   
}

map<int, int> countFrequencyOptimal(const vector<int>& numbers) {
    map<int, int> frequencyMap;
    for (int num : numbers) {
        frequencyMap[num]++;
    }
    return frequencyMap;
}

int main() {
    vector<int> numbers = {1, 2, 3, 2, 4, 1, 5, 5, 6};

    cout << "Frequency (Brute Force) :" << endl;
    countFrequencyBruteForce(numbers);

    cout << "\nFrequency (Optimal) :" << endl;
    map<int, int> frequencyMapOptimal = countFrequencyOptimal(numbers);
    for (const auto& entry : frequencyMapOptimal) {
        cout << entry.first << " : " << entry.second << " fois" << endl;
    }

    return 0;
}
