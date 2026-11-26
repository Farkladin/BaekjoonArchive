#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using pii=pair<int,int>;
vector<vector<pii> >G;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,M;cin>>N>>M;
    G.resize(N+2);
    while(M--){
        int A,B,C;cin>>A>>B>>C;
        G[A].push_back({B,C});
        G[B].push_back({A,C});
    }
    priority_queue<pii>pq;pq.push({0,1});
    vector<int>dist(N+3,1e9);
    while(!pq.empty()){
        auto [wc,u]=pq.top();pq.pop();
        if(-wc>dist[u])continue;
        for(auto [v,w]:G[u]){
            if(dist[v]>w-wc){
                dist[v]=w-wc;
                pq.push({wc-w,v});
            }
        }
    }
    cout<<dist[N]<<"\n";
    return 0;
}
