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

ll f(const ll n,const ll p){
    const ll tmp = po((mod+1-2*p%mod)%mod,n);
    return (mod+1-tmp)*po(2,mod-2)%mod;
}

ll arr[100][100],brr[103];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    ll n, X, Y; cin>>n>>X>>Y;
    for(ll i=1; i<=n; ++i){
        ll a;cin>>a;
        for(ll x=0;x<32;++x){
            if(a&(1<<x)) ++brr[x];
            for(ll y=0;y<32;++y){
                int8_t p=(a&(1<<x))!=0, q=(a&(1<<y))!=0;
                if(p&&q) ++arr[x][y];
            }
        }
    }
    
    ll p = X*po(Y,mod-2)%mod;
    ll ans=0;
    for(ll i=0; i<32; ++i){
        for(ll j=0; j<32; ++j){
            ll u=0,v=0,t=0;
            if(arr[i][j]){
                u=f(arr[i][j],p);
            }
            if(brr[i]-arr[i][j]){
                v=f(brr[i]-arr[i][j],p);
            }
            if(brr[j]-arr[i][j]){
                t=f(brr[j]-arr[i][j],p);
            }
            ans = (ans + (((1+mod-u)%mod*v%mod*t%mod)%mod + (u*(1+mod-v)%mod*(1+mod-t)%mod)) %mod * ((1LL<<(i+j)) %mod)) %mod;
        }
    }
    
    cout<<ans<<"\n";
    
    return 0;
}
