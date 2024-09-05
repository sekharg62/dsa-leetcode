#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        vector<int>merge;
        for(int i=0;i<nums1.size();i++)
            merge.push_back(nums1[i]);
        for(int i=0;i<nums2.size();i++)
            merge.push_back(nums2[i]);

     
        sort(merge.begin(),merge.end());
        int len = merge.size();
        //cout<<len;
        if(len%2 == 1)
         return merge[len/2];
        else 
        if(len%2 ==0)
        {
            
            int mid = len/2;
            //cout<<merge[mid]<<endl;
            //cout<<merge[mid-1]<<endl;
             
            //cout<<num;
            return (merge[mid]+merge[mid-1])/2;
        }
        // Implementation will go here
        return 0.0;  // Placeholder return
    }
};

int main() {
    Solution solution;
    
    vector<int> nums1 = {1, 3};  // Example sorted array 1
    vector<int> nums2 = {2,4};     // Example sorted array 2

    double median = solution.findMedianSortedArrays(nums1, nums2);
    
    cout << "The median of the two sorted arrays is: " << median << endl;

    return 0;
}
