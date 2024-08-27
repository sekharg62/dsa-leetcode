#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] != val){
                nums[k]=nums[i];
                k++;
            }
        }
        return k;
    }
};

int main() {
    Solution solution;
    
    // Example 1
    vector<int> nums1 = {3, 2, 2, 3};
    int val1 = 3;
    int newLength1 = solution.removeElement(nums1, val1);
    cout << "New length: " << newLength1 << "\n";
    cout << "Modified array: ";
    for (int i = 0; i < newLength1; ++i) {
        cout << nums1[i] << " ";
    }
    cout << "\n";

    // Example 2
    vector<int> nums2 = {0, 1, 2, 2, 3, 0, 4, 2};
    int val2 = 2;
    int newLength2 = solution.removeElement(nums2, val2);
    cout << "New length: " << newLength2 << "\n";
    cout << "Modified array: ";
    for (int i = 0; i < newLength2; ++i) {
        cout << nums2[i] << " ";
    }
    cout << "\n";

    return 0;
}
