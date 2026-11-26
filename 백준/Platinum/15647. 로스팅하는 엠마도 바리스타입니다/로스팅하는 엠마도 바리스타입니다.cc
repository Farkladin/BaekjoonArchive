#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii=pair<int,ll>;
ll dp[300003], sz[300003], ans[300003];
int8_t vis[300003];
vector<vector<pii> >G;
void f(int x){
    sz[x]=1;
    
    for(auto [y,w]:G[x]){
        if(!vis[y]){
            vis[y]=1;
            f(y);
            dp[x]+=dp[y]+sz[y]*w;
            sz[x]+=sz[y];
        }
    }
}

bool solve(){
    int N; cin>>N;
    
    G.clear();
    G.resize(N+3);
    for(int i=1;i<N;++i){
        int a,b,w; cin>>a>>b>>w;
        G[a].push_back(pii{b,w});
        G[b].push_back(pii{a,w});
    }
    
    memset(dp,0,sizeof(dp));
    memset(sz,0,sizeof(sz));
    memset(vis,0,sizeof(vis));
    
    vis[1]=1;
    f(1);
    
    memset(vis,0,sizeof(vis));
    queue<pii>q; q.push(pii{1,dp[1]});
    ans[1]=dp[1];
    vis[1]=1;
    while(!q.empty()){
        auto [x,cur]=q.front(); q.pop();
        for(auto [y,w]:G[x]){
            if(!vis[y]){
                vis[y]=1;
                ll nxt = cur + w*(N-2*sz[y]);
                ans[y] = nxt;
                q.push(pii{y,nxt});
            }
        }
    }
    
    for(int i=1;i<=N;++i){
        cout<<ans[i]<<"\n";
    }
    
    return false;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    G.reserve(100005);
    while(solve());
    
    return 0;
}
