#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.empty()) 
            return 0;

        int minPrice = prices[0]; 
        int maxProfit = 0;        

        for (int i = 1; i < prices.size(); i++)
        {
         
            if (prices[i] < minPrice)
            {
                minPrice = prices[i];
            }
            else
            {
                
                int potentialProfit = prices[i] - minPrice;
              
                maxProfit = max(maxProfit, potentialProfit);
            }
        }

        return maxProfit;
    }

    int max(int ele1, int ele2)
    {
        return (ele1 > ele2) ? ele1 : ele2;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {7,6,4,3,1};
    int res = s.maxProfit(nums);
    cout << "Maximum profit: " << res << endl;

    return 0;
}
