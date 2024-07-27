#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
    private:
    int length;
public:
    vector <int> pos;
    
    int i ,temp;
    int lengthOfLastWord(string s) {
        cout<<s.find(" ")<<endl;
        ///remove space
        s.erase(unique(s.begin(),s.end(),[](char a,char b){
            return a==' ' && b== ' ';
        }),s.end());
       // cout<<s;
        int len = s.length();
        //cout<<endl<<len<<endl;
        //calculate all space loacation
        for(i=0;i<s.size();i++){
            if(isspace(s[i])){
            pos.push_back(i+1);
            }   
        }
        cout<<endl;
        if (pos[pos.size()-1]!=len){
            temp = len-pos[pos.size()-1];
            cout<<temp;
        
            cout<<endl<<"The last word is \""; 

            for(int j=pos[pos.size()-1];j<len;j++){
                cout<<s[j];   
            }
            cout<<"\" with length "<<temp;
        }
       
         else if(pos[pos.size()-1]==len){
            temp = len-(pos[pos.size()-2])-1;
            cout<<temp;
            cout<<endl<<"The last word is \"";
            for(int j =pos[pos.size()-2];j<=len-1;j++ )
            {
                cout<<s[j];
            }
            cout<<"\" with length "<<temp;
            
            
        } 
        
        //me sekhar ghosh 
        return 0;
    }
};
int main(){
    string string;
    cout<<"enter:";
    getline(cin,string);
    Solution s;
    
    s.lengthOfLastWord(string);
}