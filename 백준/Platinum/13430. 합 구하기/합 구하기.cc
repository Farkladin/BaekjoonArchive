#include "bits/stdc++.h"
using namespace std;
using ll=long long;

constexpr ll mod = 1'000'000'007;

ll po(ll a,ll b){
    ll ret=1;
    while(b){
        if(b&1)ret=ret*a%mod;
        a=a*a%mod; b>>=1;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    ll k,n; cin>>k>>n;
    ll ret=1;
    for(ll i=n+k; i>=n; --i){
        ret=ret*i%mod;
    }
    for(ll i=k+1; i>0; --i){
        ret=ret*po(i,mod-2)%mod;
    }
    
    cout<<ret<<"\n";
    return 0;
}

/*
 C(n+1,2)
 C(n+2,3)
 C(n+3,4)
 C(n+4,5)
 ...
 C(n+k,k+1)
*/
