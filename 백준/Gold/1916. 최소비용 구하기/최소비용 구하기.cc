#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;
int dist[1003];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,M;cin>>N>>M;
    fill(dist,dist+1001,1e9);
    vector<vector<pii> >G(N+3);
    while(M--){
        int u,v,w;cin>>u>>v>>w;
        G[u].push_back({v,w});
    }
    int src,sink;cin>>src>>sink;
    dist[src]=0;
    queue<pii>q;q.push({src,0});
    while(!q.empty()){
        auto [u,cw]=q.front();q.pop();
        if(cw>dist[u])continue;
        for(auto [v,w]:G[u]){
            if(dist[v]>cw+w){
                dist[v]=cw+w;
                q.push({v,dist[v]});
            }
        }
    }
    cout<<dist[sink]<<"\n";
    return 0;
}
