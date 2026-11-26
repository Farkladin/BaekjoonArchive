#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
const ll mod=1e9+7;
ll po2[1000003]={1},arr[1000003],brr[1000003];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    for(int i=1;i<=1e6;i++){
        po2[i]=po2[i-1]*2%mod;
    }
    int n;cin>>n;
    ll cnt1=0,cnt2=0,t=0,ans=0;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        if(x==1){
            cnt1++;
        }else if(x==2){
            t=(t*2+cnt1)%mod;
        }else{
            ans=(ans+t-cnt2+mod)%mod;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
