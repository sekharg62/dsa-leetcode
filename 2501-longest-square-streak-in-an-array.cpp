#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm> 
using namespace std;
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<long long> set(nums.begin(), nums.end());
        int ans = -1;
        
        for (int& item : nums) {
            int t = 0;
            long long x = item;
            while (set.count(x)) {
                x = x * x;
                t++;
            }
            if (t > 1)
                ans = max(ans, t);
        }
        
        return ans;
    }
};

int main() {
    Solution solution;
    
    vector<int> nums = {2, 4, 16, 256, 3, 9, 27};
   
    int result = solution.longestSquareStreak(nums);
    cout << "Longest Square Streak: " << result << endl;
    
    return 0;
}
