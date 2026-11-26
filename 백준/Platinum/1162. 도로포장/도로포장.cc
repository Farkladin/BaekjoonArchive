#include "bits/stdc++.h"
using namespace std;
using ll=long long;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,M,K;cin>>N>>M>>K;
    vector<vector<pair<ll,ll> > >G(N+3);
    vector<vector<ll> >dist(N+3,vector<ll>(K+2,1e18));
    
    for(int i=0;i<M;i++){
        int x,y,w;cin>>x>>y>>w;
        G[x].push_back({y,w});
        G[y].push_back({x,w});
    }
    
    priority_queue<array<ll,3> >pq;
    dist[1][0]=0;
    pq.push({0,1,0});
    ll ans=1e18;
    while(!pq.empty()){
        auto [wu,u,n] = pq.top(); pq.pop();
        if(u==N)ans=min(ans,-wu);
        if(-wu>dist[u][n])continue;
        for(auto [v,w]:G[u]){
            if(dist[v][n]>w-wu){
                dist[v][n]=w-wu;
                pq.push({wu-w,v,n});
            }
            if(n<K && dist[v][n+1]>-wu){
                dist[v][n+1]=-wu;
                pq.push({wu,v,n+1});
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}
