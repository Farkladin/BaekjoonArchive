#include "bits/stdc++.h"
#include <format>
#define fi first
#define se second
using namespace std;
using ll=long long;
using lf=double;
using pll=pair<ll,ll>;

inline int ccw(const pll &a,const pll &b,const pll &c){
    ll cp=(b.fi-a.fi)*(c.se-a.se)-(b.se-a.se)*(c.fi-a.fi);
    return cp>0?1:(cp<0?-1:0);
}

inline bool lsi(pair<pll,pll>a,pair<pll,pll>b){
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
    int T;cin>>T;
    while(T--){
        int n,m;cin>>n>>m;
        vector<pll>wrr(m),brr(n);
        for(int i=0;i<n;i++)cin>>brr[i].fi>>brr[i].se;
        for(int i=0;i<m;i++)cin>>wrr[i].fi>>wrr[i].se;
        
        vector<pll>bhull(n+n),whull(m+m);
        sort(brr.begin(),brr.end());
        sort(wrr.begin(),wrr.end());
        
        int bk=0;
        for(auto &p:brr){
            while(bk>=2&&ccw(bhull[bk-2],bhull[bk-1],p)<=0)bk--;
            bhull[bk++]=p;
        }
        for(int i=n-2,t=bk+1;i>=0;i--){
            while(bk>=t&&ccw(bhull[bk-2],bhull[bk-1],brr[i])<=0)bk--;
            bhull[bk++]=brr[i];
        }
        bk--;
        
        int wk=0;
        for(auto &p:wrr){
            while(wk>=2&&ccw(whull[wk-2],whull[wk-1],p)<=0)wk--;
            whull[wk++]=p;
        }
        for(int i=m-2,t=wk+1;i>=0;i--){
            while(wk>=t&&ccw(whull[wk-2],whull[wk-1],wrr[i])<=0)wk--;
            whull[wk++]=wrr[i];
        }
        wk--;
        
        auto nexti=[](const int &idx,const int &k){
            return idx+1==k?0:idx+1;
        };
        
        bool ans=false;
        for(int i=0;i<m;i++){
            bool inter1=false,inter2=false;
            for(int j=0;j<bk;j++){
                pair<pll,pll>bside={bhull[j],bhull[nexti(j,bk)]};
                inter1|=lsi(bside,{wrr[i],{wrr[i].fi,-1e5}});
                inter2|=lsi(bside,{wrr[i],{wrr[i].fi,1e5}});
            }
            ans|=inter1&&inter2;
        }
        for(int i=0;i<n;i++){
            bool inter1=false,inter2=false;
            for(int j=0;j<wk;j++){
                pair<pll,pll>wside={whull[j],whull[nexti(j,wk)]};
                inter1|=lsi(wside,{brr[i],{brr[i].fi,-1e5}});
                inter2|=lsi(wside,{brr[i],{brr[i].fi,1e5}});
            }
            ans|=inter1&&inter2;
        }
        for(int i=0;i<bk;i++){
            pair<pll,pll>bside={bhull[i],bhull[nexti(i,bk)]};
            for(int j=0;j<wk;j++){
                pair<pll,pll>wside={whull[j],whull[nexti(j,wk)]};
                ans|=lsi(bside,wside);
            }
        }
        cout<<(ans?"NO\n":"YES\n");
    }
    return 0;
}
