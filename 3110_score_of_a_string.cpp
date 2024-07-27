#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int scoreOfString(string s)
    {
        int temp;
        int positive;
        int sum = 0;
        cout << s.size();
        for (int i = 0; i < s.size(); i++)
        {
            if (i + 1 == s.size())
                break;
            else
            {
                temp = int(s[i]) - int(s[i + 1]);

                sum += (temp < 0) ? -temp : temp;
            }
        }

        return sum;
        // Implementation of scoreOfString function
    }
};

int main()
{
    Solution solution;
    string s = "hello"; // Example input
    int result = solution.scoreOfString(s);
    cout << "Score of the string \"" << s << "\" is: " << result << endl;
    return 0;
}
