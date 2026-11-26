#include "bits/stdc++.h"
using namespace std;
using ll=long long;
constexpr ll mod=1e9+7;
ll facto[1000003]={1},invfacto[1000003]={1};
ll po(ll a,ll b){
    ll ret=1;
    while(b){
        if(b&1)ret=ret*a%mod;
        a=a*a%mod; b>>=1;
    }
    return ret;
}
ll C(ll n,ll k){
    return facto[n]*invfacto[k]%mod*invfacto[n-k]%mod;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    for(ll i=1;i<=1000000;++i){
        facto[i]=facto[i-1]*i%mod;
        invfacto[i]=po(facto[i],mod-2);
    }
    ll N,K;cin>>N>>K;
    ll ans=1,used=0;
    for(ll i=1;i<=K;++i){
        ans=ans*C(N-used,1+(N-i)/K)%mod;
        used+=1+(N-i)/K;
    }
    cout<<ans<<"\n";
    
    return 0;
}
