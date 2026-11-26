#include "bits/stdc++.h"
using namespace std;
using ll=long long;
vector<vector<pair<int,ll> > > G;
vector<set<int> > anc;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,m;cin>>n>>m;
    G.resize(n+3);
    anc.resize(n+3);
    
    for(int i=1;i<=m;i++){
        int u,v,w;cin>>u>>v>>w;
        G[u].emplace_back(v,w);
    }
    
    queue<int>q;
    vector<ll> dist(n+3);
    int han,rome;cin>>han>>rome;
    q.push(han);
    while(!q.empty()){
        int u=q.front(); q.pop();
        for(auto [v,w]:G[u]){
            if(dist[u]+w>dist[v]){
                dist[v]=dist[u]+w;
                anc[v].clear();
                q.push(v);
            }
            if(dist[u]+w==dist[v]){
                anc[v].insert(u);
            }
        }
    }
    cout<<dist[rome]<<"\n";
    
    vector<int8_t>vis(n+3);
    q.push(rome);
    int cnt=0;
    vis[rome]=1;
    while(!q.empty()){
        int u=q.front(); q.pop();
        cnt+=anc[u].size();
        for(auto v:anc[u]){
            if(!vis[v]){
                q.push(v);
                vis[v]=1;
            }
        }
    }
    cout<<cnt<<"\n";
    return 0;
}
