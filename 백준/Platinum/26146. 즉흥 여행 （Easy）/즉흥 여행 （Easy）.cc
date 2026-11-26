#include "bits/stdc++.h"
using namespace std;

vector<vector<int> >G,GT,SCC;
vector<int8_t> vis;
stack<int> stk;

void DFS(int x, const bool T){
    const vector<int> &g = T?GT[x]:G[x];
    for(int y:g){
        if(vis[y])continue;
        vis[y]=1;
        if(T)SCC.back().push_back(y);
        DFS(y,T);
    }
    
    if(!T) stk.push(x);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int N,M; cin>>N>>M;
    
    G.resize(N+2);
    GT.resize(N+2);
    for(int i=1;i<=M;++i){
        int v,w;cin>>v>>w;
        G[v].emplace_back(w);
        GT[w].emplace_back(v);
    }
    
    vis.resize(N+2);
    for(int x=1;x<=N;++x){
        if(vis[x])continue;
        vis[x]=1;
        DFS(x,false);
    }
    
    fill(vis.begin(),vis.end(),0);
    while(!stk.empty()){
        int x=stk.top(); stk.pop();
        if(vis[x]) continue;
        
        vis[x]=1;
        SCC.push_back({x});
        DFS(x,true);
    }
    
    cout<<(SCC.size()==1?"Yes\n":"No\n");
    return 0;
}
