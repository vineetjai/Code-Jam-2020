#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    int l=1;
    while(l<=t){
        string s;
        cin>>s;
        int n=s.length();
        int o=0;
        string ans="";
        for(int i=0;i<n;){
            if(s[i]-'0' == o) {ans+=s[i];i++;}
            else if(s[i]-'0' > o) {ans+="(";o++;}
            else {
                ans+=")";o--;
            }
        }
        while(o>0){
            ans+=")";
            o--;
        }
        cout<<"Case #"<<l<<": "<<ans<<endl;
        l++;
    }
}
