#include "bits/stdc++.h"
using namespace std;
using ll=long long;
constexpr ll mod = 1000000007;
ll facto[4000003]={1},invfacto[4000003]={1};
ll po(ll a,ll b){
    ll ret=1;
    while(b){
        if(b&1)ret=ret*a%mod;
        a=a*a%mod; b>>=1;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    
    for(ll i=1;i<=4000000;i++){
        facto[i]=facto[i-1]*i%mod;
        invfacto[i]=po(facto[i],mod-2);
    }
    
    int M;cin>>M;
    while(M--){
        int N,K;cin>>N>>K;
        cout<<facto[N]*invfacto[K]%mod*invfacto[N-K]%mod<<"\n";
    }
    return 0;
}
