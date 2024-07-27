#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void calcSubset(vector<int> &A, vector<vector<int>> &res,
                    vector<int> &subset, int index)
    {
        // Add the current subset to the result list
        cout<<"RES push"<<index<<endl<<A.size();
        res.push_back(subset);

        // Generate subsets by recursively including and
        // excluding elements
        for (int i = index; i < A.size(); i++)
        {
            // Include the current element in the subset
            cout<<"SUBSET Pushing...."<<i<<" , "<<A[i]<<endl;
            subset.push_back(A[i]);

            // Recursively generate subsets with the current
            // element included
            cout<<"Calling...."<<i+1<<endl;
            calcSubset(A, res, subset, i + 1);

            // Exclude the current element from the subset
            // (backtracking)
            cout<<"Popping...."<<i<<endl;
            subset.pop_back();
        
        }
    }
    vector<vector<int>> subsets(vector<int> &A)
    {
        vector<int> subset;
        vector<vector<int>> res;
        int index = 0;
        calcSubset(A, res, subset, index);
        return res;
    }
};

// Driver code
int main()
{
    Solution sol;
    vector<int> nums = {2,7,8};
    vector<vector<int>> result = sol.subsets(nums);

    for (const auto &subset : result)
    {
        cout << "{ ";
        for (int num : subset)
        {
            cout << num << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}