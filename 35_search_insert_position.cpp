#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int n = nums.size();
        int left = 0, right = n;
        int mid ;
        while (left<= right)
        {
            mid = left + (right - left)/2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return 0;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 3, 5, 6};
    int target = 3;
    int index = solution.searchInsert(nums, target);
    cout << "Index where " << target << " should be inserted: " << index << endl;

    return 0;
}
