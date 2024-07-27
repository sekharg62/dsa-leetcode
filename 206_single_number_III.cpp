#include <iostream>
#include <vector>
#include<stack>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // This method should be implemented in your solution
        vector<int> newStack;
        for(int i=0;i<nums.size();i++){
            cout<<"INNER "<<endl;
            newStack.push_back(nums[i]);
            for(int j=i+1;j<nums.size();j++){
                if(newStack[i]==nums[j]){
                    newStack.pop_back();
                    i--;
                    break;
                }
        }
    }
    return newStack;
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
