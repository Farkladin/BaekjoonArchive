#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
using ppp=pair<pii,pii>;

inline int ccw(const pii &a,const pii &b,const pii &c){
    ll cp=(b.fi-a.fi)*(c.se-a.se)-(b.se-a.se)*(c.fi-a.fi);
    return cp>0?1:(cp<0?-1:0);
}

bool lsi(ppp a,ppp b){
    ll ab=ccw(a.fi,a.se,b.fi)*ccw(a.fi,a.se,b.se),ba=ccw(b.fi,b.se,a.fi)*ccw(b.fi,b.se,a.se);
    if(ab==0&&ba==0){
        if(a.fi>a.se)swap(a.fi,a.se);
        if(b.fi>b.se)swap(b.fi,b.se);
        return b.fi<=a.se&&a.fi<=b.se;
    }
    return ab<=0&&ba<=0;
}

constexpr ll dx[4]={1,0,-1,0},dy[4]={0,-1,0,1};
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int L,N;cin>>L>>N;
    int d=0;
    vector<ppp>lines({{{-L-1,L+1},{-L-1,-L-1}},{{-L-1,L+1},{L+1,L+1}},{{L+1,L+1},{L+1,-L-1}},{{L+1,-L-1},{-L-1,-L-1}}});
    pii cur={0,0};
    ll curt=0;
    while(N--){
        ll t;char dir;cin>>t>>dir;
        pii tmp={cur.fi+dx[d],cur.se+dy[d]};
        pii nxt={cur.fi+dx[d]*t,cur.se+dy[d]*t};
        bool flag=false;
        ll ans=1e18;
        for(auto &l:lines){
            if(lsi(l,{tmp,nxt})){
                flag=true;
                if(d&1){
                    ans=min({abs(l.fi.se-cur.se),ans});
                }else{
                    ans=min({abs(l.fi.fi-cur.fi),ans});
                }
            }
        }
        if(flag){
            cout<<ans+curt<<"\n";
            return 0;
        }
        lines.push_back({cur,nxt});
        curt+=t;
        cur=nxt;
        if(dir=='R')d=(d+1)%4;
        else d=(d+3)%4;
    }
    
    pii tmp={cur.fi+dx[d],cur.se+dy[d]},nxt={cur.fi+dx[d]*ll(1e9),cur.se+dy[d]*ll(1e9)};
    ll ans=1e18;
    for(auto &l:lines){
        if(lsi(l,{tmp,nxt})){
            if(d&1){
                ans=min(abs(l.fi.se-cur.se),ans);
            }else{
                ans=min(abs(l.fi.fi-cur.fi),ans);
            }
        }
    }
    cout<<ans+curt<<"\n";
    return 0;
}
