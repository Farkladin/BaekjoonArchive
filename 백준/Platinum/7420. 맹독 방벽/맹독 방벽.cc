#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<ll,ll>;
constexpr double PI=3.14159265358979323846;

inline int ccw(const pii &a,const pii &b,const pii &c){
    ll cp=(b.fi-a.fi)*(c.se-a.se)-(b.se-a.se)*(c.fi-a.fi);
    if(cp>0)return 1;
    if(cp<0)return -1;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    ll L;cin>>L;
    vector<pii>arr(N),hull(N+N);
    for(int i=0;i<N;i++)cin>>arr[i].fi>>arr[i].se;
    sort(arr.begin(),arr.end());
    
    int k=0;
    for(auto &p:arr){
        while(k>=2&&ccw(hull[k-2],hull[k-1],p)<=0)k--;
        hull[k++]=p;
    }
    
    for(int i=N-2,t=k+1;i>=0;i--){
        while(k>=t&&ccw(hull[k-2],hull[k-1],arr[i])<=0)k--;
        hull[k++]=arr[i];
    }
    
    k--;
    auto dist=[&k](const pii &a,const pii &b)->double{
        return sqrt((a.fi-b.fi)*(a.fi-b.fi)+(a.se-b.se)*(a.se-b.se));
    };
    
    double ans=dist(hull[0],hull[k-1])+PI*L*2+1e-9;
    for(int i=0;i<k-1;i++){
        ans+=dist(hull[i],hull[i+1]);
    }
    cout<<ll(ans+0.5)<<"\n";
    
    return 0;
}
