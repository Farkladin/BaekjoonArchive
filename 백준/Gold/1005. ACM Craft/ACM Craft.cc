#include "bits/stdc++.h"
using namespace std;
vector<vector<int> >G;
int dp[1003],D[1003];
int f(int x){
    if(dp[x]!=-1)return dp[x];
    dp[x]=0;
    for(int y:G[x]){
        dp[x]=max(dp[x],f(y));
    }
    dp[x]+=D[x];
    return dp[x];
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int T;cin>>T;
    while(T--){
        G.clear();
        memset(dp,-1,sizeof(dp));
        memset(D,0,sizeof(D));
        int N,K;cin>>N>>K;
        G.resize(N+1);
        for(int i=1;i<=N;i++)cin>>D[i];
        while(K--){
            int u,v;cin>>u>>v;
            G[v].push_back(u);
        }
        int W;cin>>W;
        cout<<f(W)<<"\n";
    }
    return 0;
}
