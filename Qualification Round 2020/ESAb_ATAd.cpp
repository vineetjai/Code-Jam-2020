// python3 interactive_runner.py python3 test.py 0 -- ./a.out
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> a(100);
int b;
int flag1,flag2,flag3,flag4;
vector<pair<int,int>> v[2],v1[2];
void solve(){
    for(int i=0;i<b;i++) cout<<a[i];
    cout<<endl;
}
void change_a(int en){
  if(flag1==1){
    for(int i=0;i<en;i++){
      a[b-1-i]=1-a[b-1-i];
      a[i]=1-a[i];
    }
  }
  else if(flag2==1){
    for(int i=0;i<en;i++) swap(a[i],a[b-1-i]);
  }
  else if(flag3==1){
    for(int i=0;i<en;i++){
      a[b-1-i]=1-a[b-1-i];
      a[i]=1-a[i];
    }
    for(int i=0;i<en;i++) swap(a[i],a[b-1-i]);
  }
}
void find_flag(){
  int x;
  if(v[0].size()!=0 || v[1].size()!=0){
    int idx=v[0].size()!=0?v[0][0].first:v[1][0].first;
    cout<<idx+1<<endl;
    cin>>x;
    if(x!=a[idx]) flag1=flag2=1,flag3=flag4=0;
    else flag3=flag4=1,flag1=flag2=0;
  }
  else{
    cout<<1<<endl;
    cin>>x;
  }

  if(v1[0].size()!=0 || v1[1].size()!=0 ){
    int idx=v1[0].size()!=0?v1[0][0].first:v1[1][0].first;
    cout<<idx+1<<endl;
    cin>>x;
    if(x!=a[idx]){
      flag1=flag1==-1?1:flag1&1;
      flag3=flag3==-1?1:flag3&1;
      flag2=0,flag4=0;
    }
    else{
      flag2=flag2==-1?1:flag2&1;
      flag4=flag4==-1?1:flag4&1;
      flag1=0,flag3=0;
    }
  }
  else {
    cout<<1<<endl;
    cin>>x;
  }
}
void make_vector(int en){
  for(int i=0;i<en;i++)
    if(a[i]!=a[b-1-i]) v[a[i]].push_back({i,b-1-i});
    else v1[a[i]].push_back({i,b-1-i});
}
void fill_a(int st,int en){
  for(int i=st;i<en;i++){
    cout<<i+1<<endl;
    cin>>a[i];
    cout<<b-i<<endl;
    cin>>a[b-1-i];
  }
}

int main(){
    int t,x;
    string y;
    cin>>t>>b;
    while(t--){
        fill(a.begin(),a.end(),0);

        if(b==10){
          int st=0,en=5;
          fill_a(st,en);
          v[0].clear();v[1].clear();
          v1[0].clear();v1[1].clear();
          make_vector(en);
          flag1=-1,flag2=-1,flag3=-1,flag4=-1;
          find_flag();
          change_a(en);
        }
        else if(b==20){
          vector<pair<int,int>> itera={{0,5},{5,9},{9,10}};
          for(int i=0;i<itera.size();i++){
            int st=itera[i].first,en=itera[i].second;
            fill_a(st,en);
            v[0].clear();v[1].clear();
            v1[0].clear();v1[1].clear();
            make_vector(en);
            flag1=-1,flag2=-1,flag3=-1,flag4=-1;
            find_flag();
            change_a(en);
          }
        }
        else{

          vector<pair<int,int>> itera={{0,5},{5,9}};
          int x=9+4;
          while(x<50){
            itera.push_back({itera[itera.size()-1].second,x});
            x=x+4;
          }
          itera.push_back({49,50});

          for(int i=0;i<itera.size();i++){
            int st=itera[i].first,en=itera[i].second;
            fill_a(st,en);
            v[0].clear();v[1].clear();
            v1[0].clear();v1[1].clear();
            make_vector(en);
            flag1=-1,flag2=-1,flag3=-1,flag4=-1;
            find_flag();
            change_a(en);
          }
        }

        solve();
        cin>>y;
        if(y=="N") exit(0);
    }
    return 0;
}
