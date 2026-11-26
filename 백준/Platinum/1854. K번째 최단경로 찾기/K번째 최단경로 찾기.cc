#include "bits/stdc++.h"
using namespace std;
using ll=long long;
priority_queue<ll>dist[1003];
priority_queue<pair<ll,int> >pq;
vector<pair<int,ll> >G[1003];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,m,k;cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int a,b,c;cin>>a>>b>>c;
        G[a].push_back({b,c});
    }
    pq.push({0,1});
    dist[1].push(0);
    while(!pq.empty()){
        auto [wu,u]=pq.top();pq.pop();
        if(dist[u].size()==k && dist[u].top()<-wu)continue;
        for(auto [v,w]:G[u]){
            if(dist[v].size()<k || dist[v].top()>w-wu){
                dist[v].push(w-wu);
                if(dist[v].size()>k)dist[v].pop();
                pq.push({wu-w,v});
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(dist[i].size()<k)cout<<"-1\n";
        else cout<<dist[i].top()<<"\n";
    }
    return 0;
}
