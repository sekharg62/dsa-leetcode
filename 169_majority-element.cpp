#include <iostream>
#include <map>
#include <vector>

int main() {

    std::vector<int> arr = {1, 3, 5, 3, 2, 1, 5, 3, 5, 2, 1};

    
    std::map<int, int> frequencyMap;

   
    for (int i = 0; i < arr.size(); i++) {
        frequencyMap[arr[i]]++; 
    }

    
    int maxFreq = 0;
    int elementWithMaxFreq = 0;

    
    for (const auto &pair : frequencyMap) {
        if (pair.second > maxFreq) {
            maxFreq = pair.second;           
            elementWithMaxFreq = pair.first; }
    }

   
    std::cout << "Element with maximum frequency: " << elementWithMaxFreq << std::endl;
    std::cout << "Maximum frequency: " << maxFreq << std::endl;

    return 0;
}
