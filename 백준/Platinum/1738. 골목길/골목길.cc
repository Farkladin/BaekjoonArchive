#include "bits/stdc++.h"
using namespace std;
using ll=long long;

int8_t vis[103];
bool spfa(const int &N, const int &src, vector<ll>&dist, vector<vector<pair<int,ll> > >&G, vector<int>&anc){
    dist=vector<ll>(N+3,1e18);
    anc=vector<int>(N+3,-1);
    vector<int> cnt(N+3);
    vector<int8_t> inQ(N+3);
    queue<int>q; q.push(src);
    inQ[src]=1;
    cnt[1]=1;
    dist[src]=0;
    
    while(!q.empty()){
        int u=q.front();q.pop();
        inQ[u]=0;
        for(auto [v,w]:G[u]){
            if(!vis[v]) continue;
            if(dist[v] > dist[u]+w){
                anc[v]=u;
                dist[v]=dist[u]+w;
                if(!inQ[v]){
                    ++cnt[v];
                    if(cnt[v]>=N)return true;
                    q.push(v);
                    inQ[v]=1;
                }
            }
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,m;cin>>n>>m;
    vector<vector<pair<int,ll> > >G(n+3);
    vector<vector<int> >GT(n+3);
    for(int i=0;i<m;i++){
        int u,v,w;cin>>u>>v>>w;
        G[u].emplace_back(v,-w);
        GT[v].emplace_back(u);
    }
    
    queue<int>q; q.push(n);
    vis[n]=1;
    while(!q.empty()){
        int u=q.front();q.pop();
        for(auto v:GT[u]){
            if(!vis[v]){
                vis[v]=true;
                q.push(v);
            }
        }
    }
    
    if(!vis[1]){
        cout<<"-1\n";
        return 0;
    }
    
    vector<ll>dist;
    vector<int>anc;
    bool flag=spfa(n,1,dist,G,anc);
    if(flag)cout<<"-1\n";
    else{
        int x=n;
        vector<int>path{x};
        while(anc[x]!=-1){
            x=anc[x];
            path.emplace_back(x);
        }
        for(auto it=path.rbegin();it!=path.rend();++it)cout<<(*it)<<" ";
        cout<<"\n";
    }
    
    return 0;
}
