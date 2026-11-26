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

void solve(){
    int n;cin>>n;
    vector<int>cnt(300003),arr(300003);
    for(int i=1;i<=n;++i)cin>>arr[i];
    ll ans=0;
    ll j;
    
    j=1;
    for(int i=1;i<=n;++i){
        ++cnt[arr[i]];
        while(cnt[arr[i]]>1){
            if(j==1)ans=(ans+i-j-1)%mod;
            else ans=(ans+ j*j%mod*(po(j,i-j-1)%mod+mod-1)%mod*po(j-1,mod-2)%mod)%mod;
            --cnt[arr[j++]];
        }
    }
    
    for(;j<n;++j){
        if(j==1)ans=(ans+n-j)%mod;
        else ans=(ans+j*j%mod*(po(j,n-j)%mod+mod-1)%mod*po(j-1,mod-2)%mod)%mod;
    }
    
    fill(cnt.begin(),cnt.end(),0);
    
    j=n;
    for(int i=n;i>0;--i){
        ++cnt[arr[i]];
        while(cnt[arr[i]]>1){
            ans=(ans+ j*j%mod*(po(j,j-i-1)%mod+mod-1)%mod*po(j-1,mod-2)%mod)%mod;
            --cnt[arr[j--]];
        }
    }
    for(;j>1;--j){
        if(j==1)ans=(ans+j)%mod;
        else ans=(ans+j*j%mod*(po(j,j-1)%mod+mod-1)%mod*po(j-1,mod-2)%mod)%mod;
    }
    
    cout<<ans<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;cin>>T;
    while(T--)solve();
    return 0;
}
