#include <iostream>
#include <vector>
#include <algorithm>  // For transform
using namespace std;

class Solution
{
public:
    vector<string> findWords(vector<string> &words)
    {
        vector<string> result;

        for (string word : words)
        {
            if (isValid(word))
            {
                result.push_back(word);
            }
        }

        return result;
    }

private:
    bool isValid(string word)
    {
        // Convert the word to lowercase
        transform(word.begin(), word.end(), word.begin(), ::tolower);

        // Define rows of the keyboard
        string row1 = "qwertyuiop";
        string row2 = "asdfghjkl";
        string row3 = "zxcvbnm";

        // Determine the row of the first character
        int row = getRow(word[0], row1, row2, row3);

        // Check if all characters belong to the same row
        for (char c : word)
        {
            if (getRow(c, row1, row2, row3) != row)
                return false;
        }

        return true;
    }

    // Helper function to determine which row a character belongs to
    int getRow(char c, string &row1, string &row2, string &row3)
    {
        if (row1.find(c) != string::npos)
            return 1;
        if (row2.find(c) != string::npos)
            return 2;
        if (row3.find(c) != string::npos)
            return 3;
        return -1; // Should never reach here if the input is valid
    }
};

int main()
{
    Solution solution;
    vector<string> words = {"Hello", "Alaska", "Dad", "Peace"};

    // Call the function to find words that can be typed using the same row
    vector<string> result = solution.findWords(words);

    // Print the result
    for (const string &word : result)
    {
        cout << word << endl;
    }

    return 0;
}
