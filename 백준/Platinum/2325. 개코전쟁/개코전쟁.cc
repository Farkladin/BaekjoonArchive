#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<ll,ll>;

vector<pii> G[1003];
vector<ll> dist;
ll anc[1003];
bool cut[1003][1003];
ll f(const int src, const int sink, const bool flag){
    fill(dist.begin(),dist.end(),1e18);
    
    priority_queue<pii>pq; pq.push(pii{0,src});
    dist[src]=0;
    while(!pq.empty()){
        auto [wu,u] = pq.top(); pq.pop();
        if(dist[u]<-wu)continue;
        for(auto [v,w]:G[u]){
            if(dist[v]>w-wu && !cut[u][v]){
                dist[v]=w-wu;
                if(flag)anc[v]=u;
                pq.push(pii{wu-w,v});
            }
        }
    }
    
    return dist[sink];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N, M; cin>>N>>M;
    
    for(int i=1; i<=M; ++i){
        int x,y,z; cin>>x>>y>>z;
        G[x].emplace_back(y,z);
        G[y].emplace_back(x,z);
    }
    dist.resize(N+3);
    
    f(1,N,true);
    ll u = N, ans=0;
    while(anc[u]){
        cut[u][anc[u]]=cut[anc[u]][u]=true;
        ans=max(ans,f(1,N,false));
        cut[u][anc[u]]=cut[anc[u]][u]=false;
        u=anc[u];
    }
    cout<<ans<<"\n";
    
    return 0;
}
