#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
constexpr ll mod=900528;
ll mp[256],po[1000003];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    string s;cin>>s;
    ll n=(ll)s.size();
    for(ll i=0;i<n;i++)mp[s[i]]=(i+1)%mod;
    po[0]=1;
    for(ll i=1;i<=1e6;i++){
        po[i]=po[i-1]*n%mod;
    }
    string t;cin>>t;
    ll ans=0,k=t.size()-1;
    for(auto c:t){
        ans=(ans+mp[c]*po[k])%mod;
        k--;
    }
    cout<<ans<<"\n";
    return 0;
}
