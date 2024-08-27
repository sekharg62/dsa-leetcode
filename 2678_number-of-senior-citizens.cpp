#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    int countSeniors(vector<string> &details)

    {
        int count = 0;
        int num1,num2,num3;
        for(int i=0;i<details.size();i++){
            num1 = details[i][11] - '0';
            num2 = details[i][12] - '0';
            num3 = num1*10 + num2;
            if(num3 > 60)
            count ++;

        }
       
        return count; 
    }
};

int main()
{
    // Create an instance of Solution
    Solution solution;

    // Define your vector of strings (details)
    vector<string> details = {
        "7868190130M7522", "5303914400F9211", "9273338290F4010"};

    // Call the countSeniors method and store the result
    int result = solution.countSeniors(details);

    // Print the result
    cout << "Number of seniors: " << result << endl;

    return 0;
}
