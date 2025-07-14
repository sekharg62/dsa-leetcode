#include <iostream>
#include <vector>
#include <algorithm> // for std::min and std::max

using namespace std;
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int maxWater = 0;
        int left = 0;
        int right = height.size()-1;
        while (left<right)
        {
            int h = min(height[left],height[right]);
            int width = right - left;
            int current = h*width;
            maxWater=max(current,maxWater);
            if(height[left]<height[right])
            left++;
            else 
            right--;
        }
        

        return maxWater;
    }
};
 int main()
{
    // Example input
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution s ;
    int result = s.maxArea(height);

    cout << "Maximum area: " << result << endl;

    return 0;
}
