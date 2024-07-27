#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        if (s.size() == 1) {
            return 1;
        } else if (s.size() > 1) {
            unordered_map<char, int> frequency;
            for (int i = 0; i < s.size(); ++i) {
                frequency[s[i]]++;
            }

            int length = 0;
            bool odd_found = false;
            for (auto& kv : frequency) {
                if (kv.second % 2 == 0) {
                    length += kv.second;
                } else {
                    length += kv.second - 1;
                    odd_found = true;
                }
            }

            if (odd_found) {
                length += 1;  // Add one odd character in the middle
            }

            return length;
        }
        return 0;
    }
};


int main()
{
    Solution solution;
    string s = "abccccdd"; // Example input
    int result = solution.longestPalindrome(s);

    cout << "The length of the longest palindrome that can be built is: " << result << endl;

    return 0;
}