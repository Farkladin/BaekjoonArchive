#include "bits/stdc++.h"
using namespace std;
using ll=long long;
bool E[1000003];
constexpr ll mxn=1e6;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;cin>>n;
    vector<ll>arr(n,1e6);
    for(int i=0;i<n;i++)cin>>arr[i];
    ll ans=1;
    for(ll i=2;i<=mxn;i++){
        if(E[i])continue;
        ll r=(arr.front()+mxn*i)%i;
        for(auto a:arr){
            if(r!=(a+mxn*i)%i)goto FAIL;
        }
        ans=max(ans,i);
        continue;
        FAIL:
        if(i*i>mxn)continue;
        for(ll j=i+i;j<=mxn;j+=i)E[j]=true;
    }
    cout<<ans<<"\n";
    return 0;
}
