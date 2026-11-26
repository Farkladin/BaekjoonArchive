#include "bits/stdc++.h"
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,M;cin>>N>>M;
    vector<vector<pair<int,ll> > >G(N+3);
    vector<ll>dist(N+3);
    vector<array<int,3> >edges(M+3);
    
    for(int i=1;i<=M;++i){
        int S,E,L;cin>>S>>E>>L;
        G[S].emplace_back(E,L);
        G[E].emplace_back(S,L);
        edges[i]={S,E,L};
    }
    
    
    ll ans=1e18;
    for(int src=1;src<=N;src++){
        fill(dist.begin(),dist.end(),1e18);
        dist[src]=0;
        priority_queue<pair<ll,int> >pq; pq.push({0,src});
        while(!pq.empty()){
            auto [wu,u] = pq.top(); pq.pop();
            if(dist[u]<-wu)continue;
            for(auto [v,w]:G[u]){
                if(dist[v]>w-wu){
                    dist[v]=w-wu;
                    pq.push({wu-w,v});
                }
            }
        }
        
        ll mx=0;
        for(int i=1;i<=M;i++){
            ll ta=dist[edges[i][0]],tb=dist[edges[i][1]],l=edges[i][2];
            if(ta>tb)swap(ta,tb);
            if(ta+l<=tb)mx=max(mx,2*tb);
            else{
                ll d=tb-ta;
                ll t=2*d+(l-d);
                mx=max(mx,2*ta+t);
            }
        }
        ans=min(ans,mx);
    }
    
    cout<<fixed;
    cout.precision(1);
    cout<<(double)ans*0.5<<"\n";
    return 0;
}
