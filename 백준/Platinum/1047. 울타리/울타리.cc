#include "bits/stdc++.h"
using namespace std;
using ll = long long;

struct Type{
    ll x,y,t;
}arr[44];

inline bool cmp(const Type &a, const Type &b){
    return a.t>b.t;
}

ll N;
ll f(ll x1,ll x2,ll y1,ll y2){
    ll mxx=0,mxy=0,mnx=1'000'001,mny=1'000'001,wood=0,cnt=0;
    for(ll i=1; i<=N; ++i){
        if(x1<=arr[i].x&&arr[i].x<=x2 && y1<=arr[i].y&&arr[i].y<=y2){
            mxx=max(mxx,arr[i].x);
            mxy=max(mxy,arr[i].y);
            mnx=min(mnx,arr[i].x);
            mny=min(mny,arr[i].y);
        }else{
            wood+=arr[i].t;
            ++cnt;
        }
    }
    
    if(wood - (mxx-mnx)*2 - (mxy-mny)*2 >=0)return cnt;
    else{
        sort(arr+1,arr+1+N,cmp);
        for(ll i=1; i<=N; ++i){
            if(x1<=arr[i].x&&arr[i].x<=x2 && y1<=arr[i].y&&arr[i].y<=y2){
                wood+=arr[i].t;
                ++cnt;
            }
            if(wood - (mxx-mnx)*2 - (mxy-mny)*2 >=0)return cnt;
        }
    }
    return 1e18;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>N;
    vector<ll>X(N),Y(N);
    for(int i=1; i<=N; ++i){
        cin>>arr[i].x>>arr[i].y>>arr[i].t;
        X[i-1]=arr[i].x;
        Y[i-1]=arr[i].y;
    }
    sort(X.begin(),X.end());
    sort(Y.begin(),Y.end());
    
    ll ans=N;
    for(ll x1=0; x1<N; ++x1){
        for(ll x2=x1; x2<N; ++x2){
            for(ll y1=0; y1<N; ++y1){
                for(ll y2=y1; y2<N; ++y2){
                    ans=min(ans,f(X[x1],X[x2],Y[y1],Y[y2]));
                }
            }
        }
    }
    cout<<ans<<"\n";
    
    return 0;
}
