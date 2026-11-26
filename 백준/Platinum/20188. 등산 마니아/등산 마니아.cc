#include "bits/stdc++.h"
using namespace std;
using ll=long long;

ll ans=0;
ll dep[300003],num[300003],dp[300003];
vector<vector<int> > G;
void f(int x){
    num[x]=1;
    dp[x]=1;
    for(int y:G[x]){
        if(dep[y])continue;
        dep[y]=dep[x]+1;
        f(y);
        num[x]+=num[y];
        dp[x]+=dp[y]+num[y];
    }
    ll sum=0;
    ans+=(num[x]-1)*(dep[x]-1);
    for(int y:G[x]){
        if(dep[y]<dep[x])continue;
        ans+=dp[y]*(num[x]-num[y]);
        sum+=num[y]*(num[x]-num[y]-1)*(dep[x]-1);
    }
    sum>>=1;
    ans+=sum;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N;cin>>N;
    G.resize(N+3);
    for(int i=1;i<N;++i){
        int u,v;cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dep[1]=1;
    f(1);
    cout<<ans<<"\n";
    
    return 0;
}
