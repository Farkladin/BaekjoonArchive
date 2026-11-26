#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
vector<vector<pair<int,int> > >G;
int anc[1003],dep[1003],dist[1003];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,M;cin>>N>>M;
    G.resize(N+2);
    for(int i=1;i<N;i++){
        int u,v,w;cin>>u>>v>>w;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    queue<int>q;q.push(1);
    dep[1]=1;
    while(!q.empty()){
        int u=q.front();q.pop();
        for(auto [v,w]:G[u]){
            if(!dep[v]){
                anc[v]=u;
                dep[v]=dep[u]+1;
                dist[v]=dist[u]+w;
                q.push(v);
            }
        }
    }
    while(M--){
        int u,v;cin>>u>>v;
        if(dep[u]<dep[v])swap(u,v);
        int U(u),V(v);
        while(dep[U]>dep[V])U=anc[U];
        while(U!=V){
            U=anc[U];
            V=anc[V];
        }
        cout<<dist[u]+dist[v]-dist[U]*2<<"\n";
    }
    return 0;
}
