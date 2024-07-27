#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> dict = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, 
        };

        int total = 0;
        cout<<s.length();
        for (int i = 0; i < s.length(); i++) {
            if (i < s.length() - 1 && dict[s[i]] < dict[s[i + 1]]) {
                total -= dict[s[i]];
            } else {
                total += dict[s[i]];
            }
        }
        return total;
    }
};

int main() {
    Solution sol;
    
   string roman = "IX"; // Example: 1994
    int result = sol.romanToInt(roman);
    cout << "Roman numeral " << roman << " is equivalent to " << result << endl;

    return 0;
}
