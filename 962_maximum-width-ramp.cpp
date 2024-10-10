#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxWidthRamp(vector<int> &nums)
    {
        stack<int> st;
        int n = nums.size();

        // Step 1: Build a decreasing stack of indices
        for (int i = 0; i < n; i++)
        {
            if (st.empty() || nums[st.top()] > nums[i])
            {
                st.push(i);
            }
        }

        int maxRamp = 0;

        // Step 2: Traverse the array from the end and calculate the ramp
        for (int j = n - 1; j >= 0; j--)
        {
            while (!st.empty() && nums[st.top()] <= nums[j])
            {
                maxRamp = max(maxRamp, j - st.top());
                st.pop();
            }
        }

        return maxRamp;
    }
};

int main()
{
    // Input the size of the array
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);

    // Input the elements of the array
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    // Create an instance of the Solution class
    Solution solution;

    // Call the maxWidthRamp function
    int result = solution.maxWidthRamp(nums);

    // Output the result
    cout << "Maximum Width Ramp: " << result << endl;

    return 0;
}
