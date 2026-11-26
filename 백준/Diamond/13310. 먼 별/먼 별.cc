#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
using ppp=pair<pii,pii>;
constexpr pii O(0,0);

inline int ccw(const pii &a,const pii &b,const pii &c){
    ll cp=(b.fi-a.fi)*(c.se-a.se)-(b.se-a.se)*(c.fi-a.fi);
    return cp>0?1:(cp<0?-1:0);
}

pii operator-(const pii &a,const pii &b){
    return pii(a.fi-b.fi,a.se-b.se);
}

inline ll dist(const pii &a,const pii &b){
    return (a.fi-b.fi)*(a.fi-b.fi)+(a.se-b.se)*(a.se-b.se);
}

ll rotatingCallipers(vector<pii>&arr,const int &n){
    vector<pii>hull(n+n);
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
    
    auto nexti=[k](const int idx)->int{
        return idx+1==k?0:idx+1;
    };
    
    ll ret=0;
    for(int i=0,j=1;i<k;i++){
        pii p=hull[nexti(i)]-hull[i];
        while(ccw(O,p,hull[nexti(j)]-hull[j])>0)j=nexti(j);
        ret=max(ret,dist(hull[i],hull[j]));
    }
    
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,T;cin>>N>>T;
    vector<pii>arr(N),vrr(N);
    for(int i=0;i<N;i++){
        cin>>arr[i].fi>>arr[i].se>>vrr[i].fi>>vrr[i].se;
    }
    
    ll le=0,ri=T,mn=1e18,date=0;
    while(ri-le>=3){
        ll llr=(le+le+ri)/3,lrr=(le+ri+ri)/3;
        vector<pii>tmp1(arr.begin(),arr.end()),tmp2(arr.begin(),arr.end());
        for(int i=0;i<N;i++){
            tmp1[i].fi+=vrr[i].fi*llr;
            tmp1[i].se+=vrr[i].se*llr;
            tmp2[i].fi+=vrr[i].fi*lrr;
            tmp2[i].se+=vrr[i].se*lrr;
        }
        
        ll c1=rotatingCallipers(tmp1,N),c2=rotatingCallipers(tmp2,N);
        if(c2<c1)le=llr;
        else ri=lrr;
    }
    
    for(ll t=le;t<=ri;t++){
        vector<pii>tmp(arr.begin(),arr.end());
        for(int i=0;i<N;i++){
            tmp[i].fi+=vrr[i].fi*t;
            tmp[i].se+=vrr[i].se*t;
        }
        ll cur=rotatingCallipers(tmp, N);
        if(mn>cur){
            mn=cur;
            date=t;
        }
    }
    cout<<date<<"\n"<<mn<<"\n";
    return 0;
}
