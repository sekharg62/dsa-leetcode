#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
       int pos = haystack.find(needle);
       return pos;
        
    }
};
int main() {
    Solution solution;
    string haystack = "hello";
    string needle = "bh";
    
    int result = solution.strStr(haystack, needle);
    
    cout << "The position of \"" << needle << "\" in \"" << haystack << "\" is: " << result << endl;

    return 0;
}
