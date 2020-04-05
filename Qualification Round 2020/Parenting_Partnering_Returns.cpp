#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    int l=1;
    while(l<=t){
        int n;
        cin>>n;
        vector<pair<pair<int,int>,int>> v(n);
        for(int i=0;i<n;i++) {
            cin>>v[i].first.first>>v[i].first.second;
            v[i].second=i;
        }
        sort(v.begin(),v.end());
        int st_1=0,st_2=0;
        string ans="";
        int flag=0;
        map<int,string> m;
        for(int i=0;i<n;i++){
            if(st_1<=v[i].first.first){
                st_1=v[i].first.second;
                m[v[i].second]="J";
            }
            else if(st_2<=v[i].first.first){
                st_2=v[i].first.second;
                m[v[i].second]="C";
            }
            else{
                flag=1;
                break;
            }
        }
        for(auto i:m){
            ans+=i.second;
        }
        if(flag) ans="IMPOSSIBLE";
        cout<<"Case #"<<l<<": "<<ans<<endl;
        l++;
    }
}
