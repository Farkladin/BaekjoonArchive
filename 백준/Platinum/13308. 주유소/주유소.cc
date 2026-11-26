#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<ll,ll>;
using tri = array<ll,3>;
vector<vector<pii> > G;
ll dist[2503][2503], price[2503];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    ll N,M; cin>>N>>M;
    for(ll i=1; i<=N; ++i)cin>>price[i];
    
    G.resize(N+3);
    for(ll i=1; i<=M; ++i){
        ll u,v,w; cin>>u>>v>>w;
        G[u].emplace_back(v,w);
        G[v].emplace_back(u,w);
    }
    fill(&(dist[0][0]),&(dist[0][0])+2503*2503,1e18);
    priority_queue<tri> pq;
    pq.push(tri{0,1,price[1]});
    dist[1][price[1]]=0;
    
    ll ans=1e18;
    while(!pq.empty()){
        auto [wu,u,pu] = pq.top(); pq.pop();
        if(dist[u][pu]<-wu) continue;
        if(u==N) ans=min(ans,dist[u][pu]);
        for(auto [v,w]:G[u]){
            ll mn = min(price[v],pu);
            w*=pu;
            if(dist[v][mn] > w - wu){
                dist[v][mn] = w-wu;
                pq.push(tri{wu-w, v, mn});
            }
        }
    }
    
    cout<<ans<<"\n";
    
    return 0;
}
