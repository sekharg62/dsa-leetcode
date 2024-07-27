#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int appendCharacters(string s, string t) {
        int m = s.size(), n = t.size();
        int i = 0, j = 0;

       
        while (i < m && j < n) {
            if (s[i] == t[j]) {
                j++;
            }
            i++;
        }

        
        return n - j;
    }
};

int main() {
    Solution solution;
    string s = "abcde"; // Example input string s
    string t = "ace";   // Example input string t

    int result = solution.appendCharacters(s, t);

    cout << "The number of characters to append: " << result << endl;

    return 0;
}
