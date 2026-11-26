#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;

inline int ccw(const pii &a,const pii &b,const pii &c){
    ll cp=(b.fi-a.fi)*(c.se-a.se)-(b.se-a.se)*(c.fi-a.fi);
    if(cp>0)return 1;
    if(cp<0)return -1;
    return 0;
}

double dist(const pii &a, const pii &b){
    return sqrt((a.fi-b.fi)*(a.fi-b.fi)+(a.se-b.se)*(a.se-b.se));
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    vector<pii>arr(N),hull(N+N);
    for(auto &[x,y]:arr)cin>>x>>y;
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
    --k;
    hull.resize(k);
    
    double ans=0;
    for(int i=0;i<k;i++){
        int j=(i+1)%k;
        ans+=dist(hull[i],hull[j]);
    }
    cout<<fixed<<setprecision(2)<<ans<<"\n";
    return 0;
}

