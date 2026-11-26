#include "bits/stdc++.h"
using namespace std;
using ll=long long;
#define fi first
#define se second
using pii=pair<ll,ll>;
using ppp=pair<pii,pii>;

inline int ccw(const pii &a,const pii &b,const pii &c){
    ll cp=(b.fi-a.fi)*(c.se-a.se)-(b.se-a.se)*(c.fi-a.fi);
    return cp>0?1:(cp<0?-1:0);
}

inline ll CCW(const pii &a,const pii &b,const pii &c){
    return (b.fi-a.fi)*(c.se-a.se)-(b.se-a.se)*(c.fi-a.fi);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;cin>>n;
    vector<pii>arr(n),hull(n+n);
    for(auto &p:arr)cin>>p.fi>>p.se;
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
    
    ll ans=0;
    for(int i=2;i<k;i++){
        ans+=CCW(hull[0],hull[i-1],hull[i]);
    }
    cout<<abs(ans)/100<<"\n";
    return 0;
}
