#include "bits/stdc++.h"
using namespace std;
using ll=long long;
#define fi first
#define se second
using pii=pair<ll,ll>;
using ppp=pair<pii,pii>;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,L;cin>>N>>L;
    vector<pii>arr(N);
    for(auto &p:arr)cin>>p.fi>>p.se;
    sort(arr.begin(),arr.end());
    ll cur=-1e18,ans=0;
    for(auto &p:arr){
        if(cur>=p.se)continue;
        ll x=max(cur,p.fi);
        ll r=(p.se-x);
        
        ans+=r/L;
        if(r%L){
            ans++;
            cur=x+(r/L+1)*L;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
