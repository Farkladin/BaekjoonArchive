#include "bits/stdc++.h"
using namespace std;

int spt[100003][33],dep[100003],dist[100003];
vector<pair<int,int> >G[100003];

void bfs(int x0){
    queue<int>q;q.push(x0);
    dep[x0]=1;
    while(!q.empty()){
        int x=q.front();q.pop();
        for(auto [y,w]:G[x]){
            if(dep[y])continue;
            dep[y]=dep[x]+1;
            dist[y]=dist[x]+w;
            q.push(y);
            
            int k=x,r=0;
            spt[y][r]=x;
            while(spt[k][r]){
                spt[y][r+1]=spt[k][r];
                k=spt[k][r];
                r++;
            }
        }
    }
}

int bal(int u,int v){
    while(dep[u]!=dep[v]){
        int i;
        for(i=0;dep[u]<dep[spt[v][i+1]];i++);
        v=spt[v][i];
    }
    return v;
}

int lca(int u,int v){
    if(dep[u]>dep[v])swap(u,v);
    v=bal(u,v);
    while(u!=v){
        int i=0;
        for(i=0;spt[u][i+1]!=spt[v][i+1];i++);
        u=spt[u][i];v=spt[v][i];
    }
    return v;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    for(int i=1;i<N;i++){
        int x,y,w;cin>>x>>y>>w;
        G[x].emplace_back(y,w);
        G[y].emplace_back(x,w);
    }
    bfs(1);
    int M;cin>>M;
    while(M--){
        int x,y;cin>>x>>y;
        int LCA=lca(x,y);
        cout<<dist[x]+dist[y]-dist[LCA]*2<<"\n";
    }
    return 0;
}
