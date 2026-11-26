#include "bits/stdc++.h"
using namespace std;

vector<vector<int> >G,GT;
vector<int8_t> vis;
stack<int> stk;
vector<int>SCC;
int sccn[200003];
void DFS(int x, const bool T){
    const vector<int> &g = T?GT[x]:G[x];
    for(int y:g){
        if(vis[y])continue;
        vis[y]=1;
        if(T){
            SCC[y]=SCC[x];
            ++sccn[SCC[y]];
        }
        DFS(y,T);
    }
    
    if(!T) stk.push(x);
}

int dist[200003];
vector<pair<int,int> >edges;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int N; cin>>N;
    
    G.resize(N+2);
    GT.resize(N+2);
    SCC.resize(N+2);
    for(int i=1;i<=N;++i){
        int j=i, t=i;
        while(t){
            j+=t%10;
            t/=10;
        }
        if(j>N)j-=N;
        edges.emplace_back(i,j);
        G[i].push_back(j);
        GT[j].push_back(i);
    }
    
    vis.resize(N+2);
    for(int x=1;x<=N;++x){
        if(vis[x])continue;
        vis[x]=1;
        DFS(x,false);
    }
    
    fill(vis.begin(),vis.end(),0);
    int cnt=0;
    while(!stk.empty()){
        int x=stk.top(); stk.pop();
        if(vis[x]) continue;
        vis[x]=1;
        SCC[x]=++cnt;
        sccn[cnt]=1;
        DFS(x,true);
    }
    
    G.clear();
    G.resize(N+2);
    for(auto [u,v]:edges){
        if(SCC[u]!=SCC[v])G[SCC[u]].push_back(SCC[v]);
    }
    
    int mx=0;
    for(int x=1; x<=cnt; ++x){
        queue<int>q; q.push(x);
        dist[x]=max(dist[x],sccn[x]);
        mx=max(mx,dist[x]);
        while(!q.empty()){
            int u=q.front(); q.pop();
            for(int v:G[u]){
                if(dist[v]<dist[u]+sccn[v]){
                    dist[v]=dist[u]+sccn[v];
                    mx=max(dist[v],mx);
                    q.push(v);
                }
            }
        }
    }
    cout<<mx<<"\n";
    
    return 0;
}
