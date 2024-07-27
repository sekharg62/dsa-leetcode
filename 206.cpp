#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // XOR all the elements in the array. 
        int xor_all = 0;
        for (int num : nums) {
            xor_all ^= num;
        }
        cout<<"xor:"<<(xor_all);

        // Find a set bit (rightmost set bit in this case) in the xor_all result
        int set_bit = xor_all & -xor_all;

        // Divide elements into two groups and XOR separately
        int num1 = 0, num2 = 0;
        for (int num : nums) {
            if (num & set_bit) {
                num1 ^= num;
            } else {#include <bits/stdc++.h>
#include<iterator> 
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'simpleArraySum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY ar as parameter.
 */

int simpleArraySum(vector<int> ar) {
   int sum = 0;
   for(int i=0;i<ar.size();i++){
        sum = sum+ ar[i];
   }
  
    
    return sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string ar_count_temp;
    getline(cin, ar_count_temp);

    int ar_count = stoi(ltrim(rtrim(ar_count_temp)));

    string ar_temp_temp;
    getline(cin, ar_temp_temp);

    vector<string> ar_temp = split(rtrim(ar_temp_temp));

    vector<int> ar(ar_count);

    for (int i = 0; i < ar_count; i++) {
        int ar_item = stoi(ar_temp[i]);

        ar[i] = ar_item;
    }

    int result = simpleArraySum(ar);

    cout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

                num2 ^= num;
            }
        }

        return {num1, num2};
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 1, 3, 2, 5}; // Example input
    vector<int> result = solution.singleNumber(nums);

    cout << "The single numbers are: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
