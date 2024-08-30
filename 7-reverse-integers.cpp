#include<iostream>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        long long reversed = 0;
        while(x!= 0) {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }
        if(reversed < (-2^31) || reversed > (2^31-1))
        

        return reversed;
        
        
    }
};

int main(){
    Solution s;
    int x = 123;
    int result = s.reverse(x);
    cout << "Reversed number: " << result << endl;
    return 0;
}