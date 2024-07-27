#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int minPatches(vector<int> &nums, int n)
    {
        long miss = 1;
        int i = 0;
        int patch = 0;
        // int size = nums.size();
        while (miss <= n)
        {
            if (i < nums.size() && nums[i] <= miss)
            {
                miss += nums[i];
                i++;
            }
            else
            {
                miss += miss;
                patch++;
            }
            /* code */
        }
        return patch;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 3};
    int n = 6;
    int result = solution.minPatches(nums, n);
    cout << "Minimum patches required: " << result << endl;
    return 0;
}