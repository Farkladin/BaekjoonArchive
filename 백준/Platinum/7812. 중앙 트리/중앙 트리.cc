#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii=pair<int,ll>;
ll dp[100003], sz[100003];
int8_t vis[100003];
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
    int n; cin>>n;
    if(!n)return false;
    
    G.clear();
    G.resize(n+3);
    for(int i=1;i<n;++i){
        int a,b,w; cin>>a>>b>>w;
        G[a].push_back(pii{b,w});
        G[b].push_back(pii{a,w});
    }
    
    memset(dp,0,sizeof(dp));
    memset(sz,0,sizeof(sz));
    memset(vis,0,sizeof(vis));
    
    vis[0]=1;
    f(0);
    
    memset(vis,0,sizeof(vis));
    ll ans = dp[0];
    queue<pii>q; q.push(pii{0,dp[0]});
    vis[0]=1;
    while(!q.empty()){
        auto [x,cur]=q.front(); q.pop();
        for(auto [y,w]:G[x]){
            if(!vis[y]){
                vis[y]=1;
                ll nxt = cur + w*(n-2*sz[y]);
                ans = min(ans, nxt);
                q.push(pii{y,nxt});
            }
        }
    }
    
    cout<<ans<<"\n";
    
    return true;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    G.reserve(100005);
    while(solve());
    
    return 0;
}
