#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> res;
        int i = m - 1, j = n - 1;
        int k = m + n - 1;

        while (i >= 0 && j >= 0)
        {
            if (nums1[i] > nums2[j])
            {
                nums1[k--] = nums1[i--];
            }
            else
                nums1[k--] = nums2[j--];
        }
        while (j >= 0)
        {
            nums1[k--] = nums2[j--];
        }
        
    }
};

int main()
{
    // Example input
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;

    // Create a Solution object
    Solution sol;
    // Call the merge function
    sol.merge(nums1, m, nums2, n);

    // Print the result
    for (int num : nums1)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
