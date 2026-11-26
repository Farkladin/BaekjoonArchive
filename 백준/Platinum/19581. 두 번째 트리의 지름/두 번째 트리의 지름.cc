#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;
using pii=pair<ll,ll>;
pii dp[100003], ans;
int8_t vis[100003];
vector<pii> G[100003];

void g(ll &a, ll &b, ll val){
    if(val>a){
        b=a;
        a=val;
    }else if(val>b){
        b=val;
    }
}

pii f(ll x){
    vis[x]=1;
    
    auto &[a,b] = dp[x];
    
    pii mx{0,0};
    for(auto [y,w]:G[x]){
        if(vis[y]) continue;
        auto [aa,bb] = f(y);
        
        aa+=w; bb+=w;
        
        if(mx.first>0){
            g(ans.first,ans.second,mx.first+aa);
            g(ans.first,ans.second,mx.first+bb);
        }
        if(mx.second>0){
            g(ans.first,ans.second,mx.second+aa);
            g(ans.first,ans.second,mx.second+bb);
        }
        g(a,b,aa);
        g(a,b,bb);
        g(mx.first,mx.second,aa);
        g(mx.first,mx.second,bb);
    }
    
    if(a==0 && b==0){
        b=-G[x].front().second;
    }
    
    g(ans.first,ans.second,a);
    g(ans.first,ans.second,b);
    return dp[x];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll N;cin>>N;
    for(ll i=1; i<N; ++i){
        ll u,v,w; cin>>u>>v>>w;
        G[u].emplace_back(v,w);
        G[v].emplace_back(u,w);
    }
    
    (void)f(1);
    cout<<ans.second<<"\n";
    return 0;
}
