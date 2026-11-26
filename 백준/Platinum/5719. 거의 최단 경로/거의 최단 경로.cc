#include "bits/stdc++.h"
using namespace std;
using ll=long long;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    while(1){
        vector<vector<pair<int,ll> > >anc;
        vector<set<pair<int,ll> > >G;
        vector<ll>dist;
        
        int N,M,S,D;
        cin>>N>>M;
        if(N==0 && M==0)break;
        cin>>S>>D;
        anc.resize(N+3);
        G.resize(N+3);
        dist.resize(N+3);
        fill(dist.begin(),dist.end(),1e18);
        
        for(int i=1;i<=M;i++){
            int U,V,P;cin>>U>>V>>P;
            G[U].insert({V,P});
        }
        
        dist[S]=0;
        queue<int>q;q.push(S);
        while(!q.empty()){
            int u=q.front(); q.pop();
            for(auto [v,w]:G[u]){
                if(dist[u]+w < dist[v]){
                    dist[v]=dist[u]+w;
                    anc[v].clear();
                    q.push(v);
                }
                if(dist[u]+w == dist[v]){
                    anc[v].push_back({u,w});
                }
            }
        }
        
        vector<int8_t>vis(N+3);vis[D]=1;
        q.push(D);
        while(!q.empty()){
            int u=q.front();q.pop();
            for(auto [v,w]:anc[u]){
                if(!vis[v])q.push(v);
                vis[v]=1;
                G[v].erase({u,w});
            }
        }
        
        fill(dist.begin(),dist.end(),1e18);
        dist[S]=0;
        q.push(S);
        while(!q.empty()){
            int u=q.front();q.pop();
            for(auto [v,w]:G[u]){
                if(dist[u]+w < dist[v]){
                    dist[v]=dist[u]+w;
                    q.push(v);
                }
            }
        }
        
        if(dist[D]==1e18)dist[D]=-1;
        cout<<dist[D]<<"\n";
    }
    return 0;
}
