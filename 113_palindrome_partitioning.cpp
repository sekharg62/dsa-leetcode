#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> result;
        vector<string> partition;
        backtrack(result, partition, s, 0);
        return result;
    }
    void backtrack(vector<vector<string>> result, vector<string> partition, string s, int index)
    {
        string ori, rev;
        for (int i = index; i < s.size(); i++)
        {
            ori = s.substr(index, index + 1);
            rev = ori;
            reverse(ori.begin(), ori.end());
            if (ori == rev)
            {
                partition.push_back(ori);
                if (index == s.size() - 1)
                {
                    result.push_back(partition);
                }
                else
                {
                    backtrack(result, partition, s, index + 1);
                }
                partition.pop_back();
            }
        }
    }
};

int main()
{
    Solution sol;
    string input = "aab";
    vector<vector<string>> result = sol.partition(input);

    cout << "Palindromic partitions of the string \"" << input << "\":" << endl;
    for (const auto &partition : result)
    {
        cout << "{ ";
        for (const auto &str : partition)
        {
            cout << "\"" << str << "\" ";
        }
        cout << "}" << endl;
    }

    return 0;
}
