#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using lf=double;
using ll=long long;
using ull=unsigned long long;
using pii=pair<ll,ll>;
using ppp=pair<pii,pii>;

constexpr pii O(0,0);

inline int ccw(const pii &a,const pii &b,const pii &c){
    ll cp=(b.fi-a.fi)*(c.se-a.se)-(b.se-a.se)*(c.fi-a.fi);
    if(cp>0)return 1;
    if(cp<0)return -1;
    return 0;
}

pii operator-(const pii &a,const pii &b){
    return pii(a.fi-b.fi,a.se-b.se);
}

inline ll dist(const pii &a,const pii &b){
    return (a.fi-b.fi)*(a.fi-b.fi)+(a.se-b.se)*(a.se-b.se);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;cin>>n;
    vector<pii>arr(n),hull(n+n);
    for(int i=0;i<n;i++)cin>>arr[i].fi>>arr[i].se;
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
    
    ll mx=0;
    pii mxp,mxq;
    for(int i=0,j=1;i<k;i++){
        pii p=hull[nexti(i)]-hull[i];
        while(ccw(O,p,hull[nexti(j)]-hull[j])>0)j=nexti(j);
        ll cur=dist(hull[i],hull[j]);
        if(cur>mx){
            mx=cur;
            mxp=hull[i];
            mxq=hull[j];
        }
        cur=dist(hull[nexti(i)],hull[j]);
        if(cur>mx){
            mx=cur;
            mxp=hull[nexti(i)];
            mxq=hull[j];
        }
    }
    
    cout<<fixed<<setprecision(10)<<sqrt(mx)<<"\n";
    return 0;
}
