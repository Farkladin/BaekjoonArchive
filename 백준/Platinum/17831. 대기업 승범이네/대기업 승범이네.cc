#include "bits/stdc++.h"
using namespace std;
using ll=long long;
vector<int> G[200003];
ll A[200003], dp[200003][2];

void f(int x){
    for(int y:G[x]){
        f(y);
        dp[x][0]+=max(dp[y][1],dp[y][0]);
    }
    
    for(int y:G[x]){
        dp[x][1] = max(dp[x][1], dp[x][0]-max(dp[y][1],dp[y][0])+dp[y][0]+A[x]*A[y]);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N; cin>>N;
    for(int i=2; i<=N; ++i){
        int x;cin>>x;
        G[x].push_back(i);
    }
    for(int i=1;i<=N;++i)cin>>A[i];
    
    f(1);
    cout<<max(dp[1][0],dp[1][1])<<"\n";
    
    return 0;
}
