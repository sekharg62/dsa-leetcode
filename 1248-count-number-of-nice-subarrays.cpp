#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int l)
    {
        int final = 0;
        vector<int> odd_nums;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2 == 0)
                nums[i] = 0;
            else
                nums[i] = 1;
        }
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i; j < nums.size(); j++)
            {
        
                count = 0;
                for (int l = i; l <= j; l++)
                {
                    count += nums[l];
                    //cout << nums[k] << " ";
                }
                //cout<<"Count is:"<<count<<endl;
                if(count==l){
                    final++;
                }
                
                
            }
        }
        cout << endl;
        // Implementation should go here
        return final;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1,1,2,1,1}; // Example input
    int k = 3;                                         // Example k value

    int result = sol.numberOfSubarrays(nums, k);
    cout << "Number of subarrays with " << k << " odd numbers: " << result << endl;

    return 0;
}
