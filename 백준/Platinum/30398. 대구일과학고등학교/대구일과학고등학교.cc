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

ll arr[1000003];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    for(ll i=1;i<=1000000;++i){
        facto[i]=facto[i-1]*i%mod;
        invfacto[i]=po(facto[i],mod-2);
    }
    ll N,d,P; cin>>N>>d>>P;
    ll ans=1;
    for(int i=1;i<=d;++i)arr[i]=1;
    while(P--){
        ll sum=0;
        for(int i=1;i<=d;++i){
            ll q;cin>>q;
            sum+=q-arr[i];
            ans=ans*invfacto[q-arr[i]]%mod;
            arr[i]=q;
        }
        ans=ans*facto[sum]%mod;
    }
    
    {
        ll sum=0;
        for(int i=1;i<=d;++i){
            sum+=N-arr[i];
            ans=ans*invfacto[N-arr[i]]%mod;
        }
        ans=ans*facto[sum]%mod;
    }
    cout<<ans<<"\n";
    return 0;
}
