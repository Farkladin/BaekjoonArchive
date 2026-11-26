#include "bits/stdc++.h"
using namespace std;
using pii = pair<int,int>;
vector<vector<pii> > G;
int8_t vis[103][(1<<14)|3];
int gem[103];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m,K; cin>>n>>m>>K;
    G.resize(n+3);
    
    for(int i=0;i<K;++i){
        int x;cin>>x;
        gem[x]=1<<i;
    }
    
    while(m--){
        int a,b,c; cin>>a>>b>>c;
        G[a].emplace_back(b,c);
        G[b].emplace_back(a,c);
    }
    
    queue<pii>q;
    q.push(pii{1,0});
    vis[1][0]=1;
    if(gem[1]){
        vis[1][gem[1]]=1;
        q.push(pii{1,gem[1]});
    }
    while(!q.empty()){
        auto [u,cur] = q.front(); q.pop();
        for(auto [v,lim]:G[u]){
            if(lim >= __builtin_popcount(cur)){
                if(!vis[v][cur]){
                    vis[v][cur]=1;
                    q.push(pii{v,cur});
                }
                if(!vis[v][cur|gem[v]] && gem[v]){
                    vis[v][cur|gem[v]]=1;
                    q.push(pii{v,cur|gem[v]});
                }
            }
        }
    }
    
    int ans=0;
    for(int i=0; i<16384; ++i){
        if(vis[1][i]){
            ans=max(ans,__builtin_popcount(i));
        }
    }
    
    cout<<ans<<"\n";
    
    return 0;
}
