#include "bits/stdc++.h"
using namespace std;
using ll=long long;
constexpr ll mod=1e9+7;
ll po(ll a,ll b){
    ll ret=1;
    while(b){
        if(b&1)ret=ret*a%mod;
        a=a*a%mod; b>>=1;
    }
    return ret;
}

void solve(){
    ll n,k; cin>>n>>k;
    ll ans=0;
    for(ll i=1;i<=n;++i){
        ll x;cin>>x;
        ans=(ans+x)%mod;
    }
    cout<<ans*po(n,mod-2)%mod<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
