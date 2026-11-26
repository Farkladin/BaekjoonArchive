#include "bits/stdc++.h"
using namespace std;
using ll=long long;

int8_t vis[55];
bool spfa(const int &N, const int &src, vector<ll>&dist, vector<vector<pair<int,ll> > >&G){
    vector<int8_t>inQ(N+3);
    vector<int>cnt(N+3);
    queue<int>q; q.push(src);
    inQ[src]=1;
    cnt[src]=1;
    dist[src]=0;
    while(!q.empty()){
        auto u=q.front();q.pop();
        inQ[u]=false;
        for(auto [v,w]:G[u]){
            if(!vis[v])continue;
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                if(!inQ[v]){
                    cnt[v]++;
                    if(cnt[v]>=N)return true;
                    q.push(v);
                    inQ[v]=true;
                }
            }
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,src,sink,M;cin>>N>>src>>sink>>M;
    vector<vector<pair<int,ll> > >G(N+3);
    vector<vector<int> >GT(N+3);
    
    vector<array<int,3> >edges(M);
    for(auto &[u,v,w]:edges)cin>>u>>v>>w;
    
    vector<ll>earn(N+3);
    for(int i=0;i<N;i++)cin>>earn[i];
    
    for(auto &[u,v,w]:edges){
        G[u].emplace_back(v,w-earn[v]);
        GT[v].emplace_back(u);
    }
    
    vis[sink]=1;
    queue<int>q; q.push(sink);
    while(!q.empty()){
        auto u=q.front(); q.pop();
        for(auto v:GT[u]){
            if(!vis[v]){
                vis[v]=1;
                q.push(v);
            }
        }
    }
    
    if(!vis[src]){
        cout<<"gg\n";
        return 0;
    }
    
    vector<ll>dist(N+3,1e18);
    bool gee=spfa(N,src,dist,G);
    if(gee)cout<<"Gee\n";
    else cout<<-dist[sink]+earn[src]<<"\n";
    
    return 0;
}
