#include "bits/stdc++.h"
using namespace std;
using ll=long long;
ll dp[1003][1003],w[1003];
int dep[1003];
bool vis[1003];
vector<vector<int> >G;

ll g(int x,int sn){
    ll &ret=dp[x][sn];
    if(ret)return ret;
    ret=w[x];
    if(x!=sn)ret-=w[sn];
    for(int y:G[x]){
        if(dep[x]>dep[y])continue;
        ret+=min(g(y,y),g(y,sn));
    }
    return ret;
}

void dfs(int x){
    for(int y:G[x]){
        if(!dep[y]){
            dep[y]=dep[x]+1;
            dfs(y);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,root;cin>>n>>root;
    G.resize(n+2);
    for(int i=1;i<=n;i++)cin>>w[i];
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dep[root]=1;
    dfs(root);
    cout<<g(root,root)<<"\n";
    return 0;
}
