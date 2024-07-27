#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector <int> result;
        int num = 0;
         for(int i=0;i<digits.size();i++){
           num= (num*10)+digits[i];
        } 
        num=num+1;
        int rem=0;
        while(num!=0){
          rem  = num%10;
          num=num/10;
          result.push_back(rem);  
        }
        reverse(result.begin(),result.end()); 
        

        return result;
        // Implementation of plusOne function is omitted for brevity
    }
};

int main() {
    Solution sol;

    // Test cases
    vector<int> digits1 = {1, 2, 3};
    vector<int> result1 = sol.plusOne(digits1);
    cout << "Result 1: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> digits2 = {4, 3, 2, 1};
    vector<int> result2 = sol.plusOne(digits2);
    cout << "Result 2: ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
