#include "bits/stdc++.h"
using namespace std;
using ll=long long;
using pii=pair<int,int>;

int W,H;
vector<vector<pii> > g, hall;
vector<int8_t> grave;
int toIdx(int x,int y){
    return W*y+x;
}

const int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};

bool spfa(int N, int src, vector<ll>&dist, const vector<vector<pii> >&G){
    vector<int8_t>inQ(N+3);
    vector<int>cnt(N+3);
    queue<int>q; q.push(src);
    inQ[src]=1;
    cnt[src]=1;
    dist[src]=0;
    
    while(!q.empty()){
        auto u=q.front();q.pop();
        inQ[u]=false;
        if(!hall[u].empty()){
            for(auto [v,w]:hall[u]){
                if(dist[v]>dist[u]+w){
                    dist[v]=dist[u]+w;
                    if(!inQ[v]){
                        cnt[v]++;
                        if(cnt[v]>=N)return false;
                        q.push(v);
                        inQ[v]=true;
                    }
                }
            }
        }else{
            for(auto [v,w]:G[u]){
                if(dist[v]>dist[u]+w){
                    dist[v]=dist[u]+w;
                    if(!inQ[v]){
                        cnt[v]++;
                        if(cnt[v]>=N)return false;
                        q.push(v);
                        inQ[v]=true;
                    }
                }
            }
        }
    }
    return true;
}

bool solve(){
    cin>>W>>H;
    const int src=toIdx(0,0), sink=toIdx(W-1,H-1);
    if(H==0)return false;
    g.clear();
    grave.clear();
    hall.clear();
    g.resize(H*W+5);
    grave.resize(H*W+5);
    hall.resize(H*W+5);
    
    int G; cin>>G;
    while(G--){
        int X,Y; cin>>X>>Y;
        const int u=toIdx(X,Y);
        grave[u]=true;
    }
    
    int E; cin>>E;
    while(E--){
        int X1,Y1,X2,Y2,T; cin>>X1>>Y1>>X2>>Y2>>T;
        const int u=toIdx(X1,Y1), v=toIdx(X2,Y2);
        hall[u].emplace_back(v,T);
    }
    
    for(int i=0;i<W;++i){
        for(int j=0;j<H;++j){
            int u = toIdx(i,j);
            if(u==sink)continue;
            if(grave[u])continue;
            for(int dir=0; dir<4; ++dir){
                int x=dx[dir]+i, y=dy[dir]+j;
                int v=toIdx(x,y);
                if(0<=x&&x<W && 0<=y&&y<H && !grave[v]){
                    g[u].emplace_back(v,1);
                }
            }
        }
    }
    vector<ll>dist(W*H+5,1e18);
    bool flag=spfa(W*H, src, dist, g);
    if(flag){
        if(dist[sink]==1e18)cout<<"Impossible\n";
        else cout<<dist[sink]<<"\n";
    }else{
        cout<<"Never\n";
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    g.reserve(10000);
    grave.reserve(10000);
    hall.reserve(10000);
    
    while(solve());
    
    return 0;
}
