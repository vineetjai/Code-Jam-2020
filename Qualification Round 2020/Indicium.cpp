#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <utility>
#define rep(i,x,n) for(int i=x;i<n;i++)
using namespace std;

vector<vector<int>> store;
set<vector<int>> dfg;

bool check(int x,int y){
  for(int i=0;i<store[x].size();i++) if(store[x][i]==store[y][i]) return false;
  return true;
}

void recurr(vector<int> v,std::vector<int> v1,int idx){

  if(v1.size()==5 ){
    dfg.insert(v1);
    return;
  }
  if(idx>=v.size()) return;
  vector<int> v2=v1;
  v2.push_back(v[idx]);
  recurr(v,v2,idx+1);

  recurr(v,v1,idx+1);
}

int main(){
  int t;
  cin>>t;
  int lr=1;
  while(t--){
    store.clear();
    string str="IMPOSSIBLE";
    int flag=0,n,k,index;
    cin>>n>>k;
    vector<int> ans;
    vector<int> v(n);
    iota(v.begin(), v.end(), 1);
    // map<int,vector<vector<int>>> m1;
    do{
        store.push_back(v);
    }while (next_permutation(v.begin(), v.end()));

    int l=store.size();

    if(n==2){
      for(int i=0;i<l;i++){
        for(int j=0;j<l;j++){
          if(check(i,j) && store[i][0]+store[j][1]==k){
            flag=1;
            ans.push_back(i);
            ans.push_back(j);
            break;
          }
        }
        if(flag) break;
      }
    }
    else if(n==3){
      for(int i=0;i<l;i++){
        for(int j=0;j<l;j++){
          for(int w=0;w<l;w++){
            if(check(i,j) && check(j,w) && check(i,w) && store[i][0]+store[j][1]+store[w][2]==k){
              flag=1;
              ans.push_back(i);
              ans.push_back(j);
              ans.push_back(w);
              break;
            }
          }
          if(flag) break;
        }
        if(flag) break;
      }
    }
    else if(n==4){
      for(int i=0;i<l;i++){
        for(int j=0;j<l;j++){
          for(int w=0;w<l;w++){
            for(int e=0;e<l;e++){
              if(check(i,j) && check(i,w) && check(i,e) && check(j,w)&& check(j,e) && check(w,e)
              && store[i][0]+store[j][1]+store[w][2]+store[e][3]==k){
                flag=1;
                ans.push_back(i);
                ans.push_back(j);
                ans.push_back(w);
                ans.push_back(e);
                break;
              }
            }
            if(flag) break;
          }
          if(flag) break;
        }
        if(flag) break;
      }
    }
    else if(n==5){
      vector<int> v2,v3;
      for(int i=1;i<=5;i++) for(int j=1;j<=5;j++) v2.push_back(i);

      recurr(v2,v3,0);
      vector<vector<int>> v4;

      for(auto i:dfg){
        int sum=accumulate(i.begin(),i.end(),0);
        if(sum==k) v4.push_back(i);
      }

      // if(v4.size()){
      //   cout<<v4.size()<<endl;
      // }
      // for(int i=0;i<v4.size();i++){
        // for(int j=0;j<v4[i].size();j++) cout<<v4[i][j]<<" ";
        // cout<<endl;
      // }
    }

    int mat[5][5];
    if(n==5){
      if(k==5 || k==25 || k==15 || k==10 || k==20){
        int st=k/5;
        for(int i=0;i<5;i++) mat[i][i]=st;
        for(int i=0;i<5;i++){
          for(int j=i+1;j<5;j++){
            mat[i][j]= mat[i][j-1]!=5?mat[i][j-1]+1:1;
          }
          for(int j=i-1;j>=0;j--){
            mat[i][j]=mat[i][j+1]!=1?mat[i][j+1]-1:5;
          }
        }
        flag=1;
      }
      else if(k==16 || k==12 || k==13 || k==18){
        flag=1;
        int st=0;
        vector<vector<int>> x={{1,2,3,4,5},{2,4,1,5,3},{3,5,4,2,1},{4,1,5,3,2},{5,3,2,1,4}};
        if(k==12) st=1;
        if(k==18) st=4;
        if(k==13) st=3;
        rep(i,0,n) rep(j,0,n) mat[i][j]= x[i][(st+j)%5];
      }
      else if(k==23 || k==11){
        flag=1;
        int st=0;
        vector<vector<int>> x={{5,1,4,3,2},{4,5,2,1,3},{3,4,5,2,1},{2,3,1,4,5},{1,2,3,5,4}};
        if(k==11) st=1;
        rep(i,0,n) rep(j,0,n) mat[i][j]= x[i][(st+j)%5];
      }
      else if(k==7 || k==19 || k==14){
        flag=1;
        int st=0;
        vector<vector<int>> x={{1,5,2,3,4},{2,1,4,5,3},{3,2,1,4,5},{4,3,5,2,1},{5,4,3,1,2}};
        if(k==19) st=1;
        if(k==14) st=4;
        rep(i,0,n) rep(j,0,n) mat[i][j]= x[i][(st+j)%5];
      }
      else if(k==9 || k==17 ){
        flag=1;
        int st=0;
        vector<vector<int>> x={{1,5,3,4,2},{3,1,2,5,4},{4,3,1,2,5},{2,4,5,3,1},{5,2,4,1,3}};
        if(k==17) st=2;
        rep(i,0,n) rep(j,0,n) mat[i][j]= x[i][(st+j)%5];
      }
      else if(k==21){
        flag=1;
        int st=0;
        vector<vector<int>> x={{5,1,3,4,2},{3,5,2,1,4},{4,3,5,2,1},{2,4,1,3,5},{1,2,4,5,3}};
        rep(i,0,n) rep(j,0,n) mat[i][j]= x[i][(st+j)%5];
      }
      else if(k==22){
        flag=1;
        int st=0;
        vector<vector<int>> x={{4,1,5,3,2},{5,4,2,1,3},{3,5,4,2,1},{2,3,1,5,4},{1,2,3,4,5}};
        rep(i,0,n) rep(j,0,n) mat[i][j]= x[i][(st+j)%5];
      }
      else if(k==8){
        flag=1;
        int st=0;
        vector<vector<int>> x={{1,2,3,4,5},{2,1,4,5,3},{3,5,1,2,4},{5,4,2,3,1},{4,3,5,1,2}};
        rep(i,0,n) rep(j,0,n) mat[i][j]= x[i][(st+j)%5];
      }
    }
    if(flag) str="POSSIBLE";
    cout<<"Case #"<<lr<<": "<<str<<endl;
    if(flag){
      if(n==5){
        for(int i=0;i<5;i++){
          for(int j=0;j<5;j++) cout<<mat[i][j]<<" ";
          cout<<endl;
        }
      }
      else{
        for(int i=0;i<ans.size();i++){
          for(int j=0;j<store[ans[i]].size();j++) cout<<store[ans[i]][j]<<" ";
          cout<<endl;
        }
      }
    }

    lr++;
  }
}
