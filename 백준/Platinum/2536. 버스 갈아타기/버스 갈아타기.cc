#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
using ppp=pair<pii,pii>;
inline int ccw(const pii &a,const pii &b,const pii &c){
    ll cp=(b.fi-a.fi)*(c.se-a.se)+(b.se-a.se)*(c.fi-a.fi);
    return cp>0?1:(cp<0?-1:0);
}

inline bool lsi(ppp a,ppp b){
    ll ab=ccw(a.fi,a.se,b.fi)*ccw(a.fi,a.se,b.se),ba=ccw(b.fi,b.se,a.fi)*ccw(b.fi,b.se,a.se);
    if(ab==0&&ba==0){
        if(a.fi>a.se)swap(a.fi,a.se);
        if(b.fi>b.se)swap(b.fi,b.se);
        return b.fi<=a.se&&a.fi<=b.se;
    }
    return ab<=0&&ba<=0;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,m;cin>>n>>m;
    int k;cin>>k;
    vector<vector<int> >G(k+5);
    vector<ppp>bus(k+5);
    const int src=k+1,sink=k+2;
    for(int i=1;i<=k;i++){
        int b;cin>>b>>bus[i].fi.fi>>bus[i].fi.se>>bus[i].se.fi>>bus[i].se.se;
        for(int j=1;j<i;j++){
            if(lsi(bus[i],bus[j])){
                G[i].push_back(j);
                G[j].push_back(i);
            }
        }
    }
    int sx,sy,dx,dy;cin>>sx>>sy>>dx>>dy;
    for(int i=1;i<=k;i++){
        if(lsi({{sx,sy},{sx,sy}},bus[i])){
            G[src].push_back(i);
            G[i].push_back(src);
        }
        if(lsi({{dx,dy},{dx,dy}},bus[i])){
            G[sink].push_back(i);
            G[i].push_back(sink);
        }
    }
    queue<int>q;q.push(src);
    vector<int>vis(k+5);
    vis[src]=1;
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int v:G[u]){
            if(!vis[v]){
                vis[v]=vis[u]+1;
                q.push(v);
            }
        }
    }
    cout<<vis[sink]-2<<"\n";
    return 0;
}
