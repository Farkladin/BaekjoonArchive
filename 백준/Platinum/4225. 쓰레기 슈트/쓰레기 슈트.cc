#include "bits/stdc++.h"
#include <format>
#define fi first
#define se second
using namespace std;
using ll=long long;
using lf=double;
using pll=pair<lf,lf>;

inline int ccw(const pll &a,const pll &b,const pll &c){
    ll cp=(b.fi-a.fi)*(c.se-a.se)-(b.se-a.se)*(c.fi-a.fi);
    return cp>0?1:(cp<0?-1:0);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tc=0;
    while(1){
        tc++;
        int n;cin>>n;
        if(n==0)break;
        vector<pll>arr(n),hull(n+n);
        for(int i=0;i<n;i++){
            cin>>arr[i].fi>>arr[i].se;
        }
        sort(arr.begin(),arr.end());
        
        int k=0;
        for(auto &p:arr){
            while(k>=2&&ccw(hull[k-2],hull[k-1],p)<=0)k--;
            hull[k++]=p;
        }
        
        for(int i=n-2,t=k+1;i>=0;i--){
            while(k>=t&&ccw(hull[k-2],hull[k-1],arr[i])<=0)k--;
            hull[k++]=arr[i];
        }
        
        k--;
        auto nexti=[&k](const int &idx)->int{
            return idx==k?0:idx+1;
        };
        
        auto sdist=[](const pair<pll,pll> &l,const pll &p)->double{
            pll u={l.se.fi-l.fi.fi,l.se.se-l.fi.se};
            pll v={p.fi-l.fi.fi,p.se-l.fi.se};
            double k=(u.fi*v.fi+u.se*v.se)/(u.fi*u.fi+u.se*u.se);
            v={v.fi-k*u.fi,v.se-k*u.se};
            return sqrt(v.fi*v.fi+v.se*v.se);
        };
        
        lf ans=1e18;
        for(int i=0;i<k;i++){
            pair<pll,pll>side={hull[i],hull[nexti(i)]};
            lf cur=0;
            for(int j=0;j<k;j++){
                cur=max(cur,sdist(side,hull[j]));
            }
            ans=min(ans,cur);
        }
        lf tmp=ll(ans*100)/100.0;
        if(tmp+1e-18<ans)tmp+=0.01;
        cout<<format("Case {:d}: {:.2f}\n",tc,tmp);
    }
    return 0;
}
