#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> newst;
        for (int i = 0; i < s.length(); i++) {
            if (newst.empty()) {
                newst.push(s[i]);
            } else if ((s[i] == ')' && newst.top() == '(') || (s[i] == '}' && newst.top() == '{') || (s[i] == ']' && newst.top() == '[')) {
                newst.pop();
            } else {
                newst.push(s[i]);
            }
        }
        return newst.empty();
    }
};

int main() {
    Solution sol;

    string s1 = "()"; // Example: valid
    cout << "Is \"" << s1 << "\" valid? " << (sol.isValid(s1) ? "Yes" : "No") << endl;

    string s2 = "()[]{}"; // Example: valid
    cout << "Is \"" << s2 << "\" valid? " << (sol.isValid(s2) ? "Yes" : "No") << endl;

    string s3 = "(]"; // Example: invalid
    cout << "Is \"" << s3 << "\" valid? " << (sol.isValid(s3) ? "Yes" : "No") << endl;

    string s4 = "([)]"; // Example: invalid
    cout << "Is \"" << s4 << "\" valid? " << (sol.isValid(s4) ? "Yes" : "No") << endl;

    string s5 = "{[]}"; // Example: valid
    cout << "Is \"" << s5 << "\" valid? " << (sol.isValid(s5) ? "Yes" : "No") << endl;

    return 0;
}
