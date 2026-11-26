#include "bits/stdc++.h"
using namespace std;
vector<vector<int> >G,GT,SCC;
vector<bool>vis;
stack<int>stk;

void DFS(int x,const bool T){
    vector<int>&g=T?GT[x]:G[x];
    for(int y:g){
        if(vis[y])continue;
        vis[y]=true;
        if(T)SCC.back().push_back(y);
        DFS(y,T);
    }
    if(!T)stk.push(x);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,M;cin>>N>>M;
    G.resize(N+2);GT.resize(N+2);vis.resize(N+2);
    for(int i=0;i<M;i++){
        int u,v;cin>>u>>v;
        G[u].push_back(v);
        GT[v].push_back(u);
    }
    
    fill(vis.begin(),vis.end(),false);
    for(int x=1;x<=N;x++){
        if(vis[x])continue;
        vis[x]=true;
        DFS(x,false);
    }
    
    vector<int>cap(N+2);
    for(int i=1;i<=N;i++)cin>>cap[i];
    
    fill(vis.begin(),vis.end(),false);
    vector<int>grp(N+2),W(N+2);
    int cnt=0;
    while(!stk.empty()){
        int x=stk.top();stk.pop();
        if(vis[x])continue;
        vis[x]=true;
        SCC.push_back({x});
        DFS(x,true);
        cnt++;
        for(int u:SCC.back()){
            grp[u]=cnt;
            W[cnt]+=cap[u];
        }
    }
    
    vector<vector<int> >tmp(G);
    G.clear();
    G.resize(cnt+2);
    for(int x=1;x<=N;x++){
        for(int y:tmp[x]){
            if(grp[x]!=grp[y]){
                G[grp[x]].push_back(grp[y]);
            }
        }
    }
    
    int src,P;cin>>src>>P;
    vector<int>sink(P);
    for(auto &x:sink){
        cin>>x;
        x=grp[x];
    }
    
    vector<int>dist(cnt+2,0);
    queue<int>q;q.push(grp[src]);
    dist[grp[src]]=W[grp[src]];
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int v:G[u]){
            if(dist[v]<dist[u]+W[v]){
                dist[v]=dist[u]+W[v];
                q.push(v);
            }
        }
    }
    int mx=0;
    for(int x:sink)mx=max(mx,dist[x]);
    cout<<mx<<"\n";
    return 0;
}
