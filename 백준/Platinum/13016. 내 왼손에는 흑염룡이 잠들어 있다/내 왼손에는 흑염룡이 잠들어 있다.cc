#include "bits/stdc++.h"
using namespace std;
using pii = pair<int,int>;
vector<vector<pii> >G;

int dist[50003], D[50003];
void dfs(int u){
    for(auto [v,w]:G[u]){
        if(dist[v]==-1){
            dist[v]=dist[u]+w;
            D[v] = max(D[v], dist[v]);
            dfs(v);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N; cin>>N;
    G.resize(N+3);
    for(int i=1; i<N; ++i){
        int a,b,c; cin>>a>>b>>c;
        G[a].emplace_back(b,c);
        G[b].emplace_back(a,c);
    }
    
    memset(dist,-1,sizeof(dist));
    dist[1]=0;
    dfs(1);
    int mx=0,idx=0;
    for(int i=1; i<=N; ++i){
        if(mx<dist[i]){
            mx=dist[i];
            idx=i;
        }
    }
    
    memset(dist,-1,sizeof(dist));
    dist[idx]=0;
    dfs(idx);
    
    idx=mx=0;
    for(int i=1; i<=N; ++i){
        if(mx<dist[i]){
            mx=dist[i];
            idx=i;
        }
    }
    
    memset(dist,-1,sizeof(dist));
    dist[idx]=0;
    dfs(idx);
    
    for(int i=1; i<=N; ++i){
        cout<<D[i]<<"\n";
    }
    
    return 0;
}
