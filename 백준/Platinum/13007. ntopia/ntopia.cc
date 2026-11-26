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
    if(n<k)return 0;
    return facto[n]*invfacto[k]%mod*invfacto[n-k]%mod;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    for(ll i=1;i<=1000000;++i){
        facto[i]=facto[i-1]*i%mod;
        invfacto[i]=po(facto[i],mod-2);
    }
    
    ll S,a,b,c;cin>>S>>a>>b>>c;
    ll ans=0,sign=1;
    for(ll k=S; k>0; --k){
        ans=(ans + mod + sign * (C(k,a)*C(k,b)%mod*C(k,c)%mod * C(S,k)%mod))%mod;
        sign*=-1;
    }
    cout<<ans<<"\n";
    return 0;
}
