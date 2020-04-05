#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    int l=1;
    while(l<=t){
        int n;
        cin>>n;
        int a[n][n];
        int t=0,r=0,c=0;
        for(int i=0;i<n;i++){
            set<int> s;
            for(int j=0;j<n;j++){
                cin>>a[i][j];
                s.insert(a[i][j]);
            }
            t+=a[i][i];
            if(s.size()!=n) r++;
        }
        for(int j=0;j<n;j++){
            set<int> s;
            for(int i=0;i<n;i++)s.insert(a[i][j]);
            if(s.size()!=n) c++;
        }
        cout<<"Case #"<<l<<": "<<t<<" "<<r<<" "<<c<<endl;
        l++;
    }
}
