#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int n = nums.size();
        //cout<<n<<endl;
        int left = 0, right = n-1;
        int mid ;
        while (left<= right)
        {
            mid =left+(right-left )/2;
            if(nums[n-1] < target)
            return n; 

            if (nums[mid] == target)
                return mid;
            
            else if(nums[mid]<target && nums[mid+1]>target)
            return mid+1;
            else if (nums[mid] < target)

                left = mid + 1;
            else
                right = mid - 1;
        }
        return 0;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 3, 5, 6};
    int target = 7;
    int index = solution.searchInsert(nums, target);
    cout << "Index where " << target << " should be inserted: " << index << endl;

    return 0;
}
