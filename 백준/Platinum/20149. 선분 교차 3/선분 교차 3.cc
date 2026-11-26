#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using lf=double;
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

inline pair<lf,lf> inter(ppp a,ppp b){
    if(a.fi>a.se)swap(a.fi,a.se);
    if(b.fi>b.se)swap(b.fi,b.se);
    if(a>b)swap(a,b);
    ll denom=(a.fi.fi-a.se.fi)*(b.fi.se-b.se.se)-(a.fi.se-a.se.se)*(b.fi.fi-b.se.fi);
    
    if(denom==0){
        if(a.fi<=a.se&&a.se<=b.fi&&b.fi<=b.se){
            if(a.fi==b.fi||a.fi==b.se)return a.fi;
            if(a.se==b.fi||a.se==b.se)return a.se;
        }
        return {nanf("1"),nanf("1")};
    }
    pair<lf,lf>ret;
    ret.fi=((double)(a.fi.fi*a.se.se-a.fi.se*a.se.fi)*(b.fi.fi-b.se.fi)-(double)(b.fi.fi*b.se.se-b.fi.se*b.se.fi)*(a.fi.fi-a.se.fi));
    ret.fi/=denom;
    ret.se=((double)(a.fi.fi*a.se.se-a.fi.se*a.se.fi)*(b.fi.se-b.se.se)-(double)(b.fi.fi*b.se.se-b.fi.se*b.se.fi)*(a.fi.se-a.se.se));
    ret.se/=denom;
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ppp a,b;cin>>a.fi.fi>>a.fi.se>>a.se.fi>>a.se.se>>b.fi.fi>>b.fi.se>>b.se.fi>>b.se.se;
    cout<<fixed;
    cout.precision(10);
    if(lsi(a,b)){
        auto res=inter(a,b);
        cout<<"1\n";
        if(!isnan(res.fi)&&!isnan(res.se)){
            cout<<res.fi<<" "<<res.se<<"\n";
        }
    }else{
        cout<<"0\n";
    }
    
    return 0;
}
