#include <iostream>
using namespace std;
class Solution {
public:
    string reversePrefix(string word, char ch) {
        string res;
        int len;
        cout<<ch;
        for(int i=0;i<word.length();i++){
            if(word[i]==ch){
                len = i;
                break;
            }
        }
        int z=0;
        for (int j = len;j>=0;j--){
            res[z]=word[j];
            z++;
        }
        for(int k=len;k<word.length();k++){
            res[k]=word[k];

        }
        for(int u =0;u<word.length();u++){
            cout<<res[u];
        }
        return res;
    }
};
int main(){
    Solution s;
    string word ;
    getline(cin,word);
    char c ;
    cin>>c;
    string res = s.reversePrefix(word,c);
    cout<<res;
    return 0 ;
}