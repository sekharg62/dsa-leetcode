#include <iostream>
#include<climits>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> minFreq(26, INT_MAX); // To store the minimum frequency of each character across all words

        for (const string& word : words) {
            vector<int> freq(26, 0); // Frequency of each character in the current word

            for (char c : word) {
                freq[c - 'a']++;
            }

            for (int i = 0; i < 26; i++) {
                minFreq[i] = min(minFreq[i], freq[i]);
            }
        }

        vector<string> result;

        for (int i = 0; i < 26; i++) {
            while (minFreq[i] > 0) {
                result.push_back(string(1, i + 'a'));
                minFreq[i]--;
            }
        }

        return result;
    }
};

int main() {
    Solution solution;
    vector<string> words = {"bella", "label", "roller"};
    vector<string> commonCharacters = solution.commonChars(words);

    for (const string& character : commonCharacters) {
        cout << character << " ";
    }
    cout << endl;

    return 0;
}

