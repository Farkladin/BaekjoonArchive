#include "bits/stdc++.h"
using namespace std;

int dp[1003][1003],N,W;
pair<int,int> arr[1003], anc[1003][1003];

int dist(const pair<int,int> &a, const pair<int,int> &b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int f(int i,int j,int k){
    int &ret = dp[i][j];
    if(ret!=-1)return ret;
    if(k>W)return 0;
    
    int can1 = f(k,j,k+1) + dist(arr[i],arr[k]), can2 = f(i,k,k+1) + dist(arr[j],arr[k]);
    if(can1 < can2){
        anc[i][j] = {k,j};
        ret = can1;
    }else{
        anc[i][j] = {i,k};
        ret = can2;
    }
    
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin>>N>>W;
    for(int i=1;i<=W;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    memset(dp,-1,sizeof(dp));
    arr[0]={1,1};
    arr[W+1]={N,N};
    cout<<f(0,W+1,1)<<"\n";
    
    pair<int,int> tmp = {0,W+1};
    int it=0;
    while(tmp.first!=W && tmp.second!=W){
        tmp = anc[tmp.first][tmp.second];
        if(tmp.first == ++it){
            cout<<"1\n";
        }else cout<<"2\n";
    }
    
    return 0;
}
