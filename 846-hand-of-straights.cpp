#include <iostream>
#include <vector>
#include<map>
#include<queue>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> freq;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> prq;
        for(int i=0;i<hand.size();i++){
            int element = hand[i];
            freq[element]++;
        }
        for(auto it:freq)
        cout<<it.first<<" : "<<it.second<<endl;
        for(const auto& entry : freq){
            prq.push(entry);
        }
        for(int i=0;i<groupSize;i++){
            if(prq.empty()){
                return 1;
            }
            int element = prq.top().first;  
            int count = prq.top().second;
            prq.pop();
            
        }

        /* cout<<"Queue is"<<endl;
        while(!prq.empty()){
            cout<<prq.top().first<<" : "<<prq.top().second<<endl;
            prq.pop();
        } */
        cout<<endl;
        

        return 1;
        // Add your implementation here
    }
};

int main() {
    Solution solution;
    vector<int> hand1 = {1, 2, 3, 6, 2, 3, 4, 7, 8};
    int groupSize1 = 3;
    
    vector<int> hand2 = {1, 2, 3, 4, 5};
    int groupSize2 = 4;

    // Test case 1
    bool result1 = solution.isNStraightHand(hand1, groupSize1);
    cout << "Test case 1: " << (result1 ? "true" : "false") << endl;

    // Test case 2
    bool result2 = solution.isNStraightHand(hand2, groupSize2);
    cout << "Test case 2: " << (result2 ? "true" : "false") << endl;

    return 0;
}
