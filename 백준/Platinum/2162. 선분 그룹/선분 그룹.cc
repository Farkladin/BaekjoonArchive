#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<ll,ll>;
using ppp=pair<pii,pii>;

inline int ccw(const pii &a,const pii &b,const pii &c){
    ll cp=(b.fi-a.fi)*(c.se-b.se)-(b.se-a.se)*(c.fi-b.fi);
    if(cp>0)return 1;
    if(cp<0)return -1;
    return 0;
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
    int N;cin>>N;
    vector<vector<int> >G(N+3);
    vector<ppp>vl(N+3);
    for(int i=1;i<=N;i++){
        auto &line=vl[i];
        cin>>line.fi.fi>>line.fi.se>>line.se.fi>>line.se.se;
        for(int j=1;j<i;j++){
            if(lsi(vl[j],line)){
                G[i].push_back(j);
                G[j].push_back(i);
            }
        }
    }
    
    vector<bool>vis(N+3);
    int cntg=0,mx=0;
    for(int i=1;i<=N;i++){
        if(vis[i])continue;
        queue<int>q;q.push(i);
        vis[i]=true;
        cntg++;
        int cnt=1;
        while(!q.empty()){
            auto u=q.front();q.pop();
            for(auto v:G[u]){
                if(vis[v])continue;
                vis[v]=true;
                q.push(v);
                cnt++;
            }
        }
        mx=max(mx,cnt);
    }
    cout<<cntg<<"\n"<<mx<<"\n";

    return 0;
}
