#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;cin>>n;
    ll ans=0;
    vector<pair<int,int> >vp;
    while(n--){
        int L;cin>>L;
        vector<ll>dp(L+2);
        int anc=1,le=0,ri=0;
        ll mx=-1e18;
        for(int i=1;i<=L;i++){
            ll x;cin>>x;
            if(dp[i-1]>0){
                dp[i]=dp[i-1]+x;
            }else{
                anc=i;
                dp[i]=x;
            }
            if(mx<dp[i]){
                mx=dp[i];
                le=anc;
                ri=i;
            }else if(mx==dp[i]&&ri-le>i-anc){
                ri=i;
                le=anc;
            }
        }
        ans+=mx;
        vp.push_back({le,ri});
    }
    cout<<ans<<"\n";
    for(auto p:vp)cout<<p.fi<<" "<<p.se<<"\n";
    return 0;
}
