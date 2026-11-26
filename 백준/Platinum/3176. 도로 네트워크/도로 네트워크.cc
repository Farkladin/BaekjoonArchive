#include "bits/stdc++.h"
using namespace std;

struct Sparse{
    int min,max,anc;
    Sparse(int a=1e9,int b=0,int c=0): min(a), max(b), anc(c){}
}table[100003][33];

int dep[100003];
vector<pair<int,int> > G[100003];

void bfs(int src){
    queue<int>q; q.push(src);
    dep[src]=1;
    while(!q.empty()){
        int u=q.front(); q.pop();
        for(auto [v,w]:G[u]){
            if(dep[v])continue;
            dep[v]=dep[u]+1;
            q.push(v);
            
            int k=u,r=0,mn=w,mx=w;
            table[v][r]=Sparse{mn,mx,u};
            while(table[k][r].anc){
                mn=min(mn,table[k][r].min);
                mx=max(mx,table[k][r].max);
                table[v][r+1]=Sparse{mn,mx,table[k][r].anc};
                k=table[k][r].anc;
                ++r;
            }
        }
    }
}

int bal(int u,int v){
    while(dep[u]!=dep[v]){
        int i=0;
        while(dep[u]<dep[table[v][i+1].anc]) ++i;
        v=table[v][i].anc;
    }
    
    return v;
}

int lca(int u,int v){
    if(dep[u]>dep[v])swap(u,v);
    v=bal(u,v);
    while(u!=v){
        int i=0;
        while(table[u][i+1].anc != table[v][i+1].anc)++i;
        u=table[u][i].anc; v=table[v][i].anc;
    }
    
    return v;
}

pair<int,int> findMinmax(int u,int v,int anc){
    int mn=1e9, mx=0;
    while(dep[u]!=dep[anc]){
        int i=0;
        while(dep[anc]<dep[table[u][i+1].anc]) ++i;
        
        mn=min(mn, table[u][i].min);
        mx=max(mx, table[u][i].max);
        u=table[u][i].anc;
    }
    
    while(dep[v]!=dep[anc]){
        int i=0;
        while(dep[anc]<dep[table[v][i+1].anc]) ++i;
        
        mn=min(mn, table[v][i].min);
        mx=max(mx, table[v][i].max);
        v=table[v][i].anc;
    }
    
    return pair<int,int>{mn,mx};
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N; cin>>N;
    for(int i=1; i<N; ++i){
        int A,B,C; cin>>A>>B>>C;
        G[A].emplace_back(B,C);
        G[B].emplace_back(A,C);
    }
    
    bfs(1);
    
    int K; cin>>K;
    while(K--){
        int D,E; cin>>D>>E;
        int ANC=lca(D,E);
        auto [mn,mx] = findMinmax(D, E, ANC);
        cout<<mn<<" "<<mx<<"\n";
    }
    return 0;
}
