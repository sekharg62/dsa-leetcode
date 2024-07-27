#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution
{
private:
    map<string, string> mapped ;
    map <string,string> :: iterator it;


public:
    bool isIsomorphic(string s, string t)
    {
        if(s.length()==t.length()){
            for(int i=0;i<s.length();i++){
                mapped [s[i]]=t[i];
            }
            //return 1;

        }
        else return 0;
        for(it= mapped.begin();it!=mapped.end();it++){
            cout<<(*it).first <<": "<<(*it).second<<endl;
            
        }
    }
};
int main()
{
    int res;
    string s, t;
    cout << "enter string:"<<endl;
    getline(cin, s);
    getline(cin, t);
   
    Solution obj;
    res = obj.isIsomorphic(s, t);
    cout<<endl<<res;
}