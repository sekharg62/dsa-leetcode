#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        vector<char> temp ;
        for(int i=0;i<s.size();i++){
            temp.push_back(s[s.size()-1-i]);
        }
        s = temp;
    }
};

int main() {
    Solution solution;
    vector<char> s = {'h', 'e', 'l', 'l', 'o'}; // Example input

    cout << "Original string: ";
    for (char c : s) {
        cout << c;
    }
    cout << endl;

    solution.reverseString(s);

    cout << "Reversed string: ";
    for (char c : s) {
        cout << c;
    }
    cout << endl;

    return 0;
}
