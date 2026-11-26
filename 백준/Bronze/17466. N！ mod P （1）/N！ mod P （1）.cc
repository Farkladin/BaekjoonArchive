#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll N,P,ans=1;cin>>N>>P;
    for(ll i=1;i<=N;i++){
        ans=ans*i%P;
    }
    cout<<ans<<"\n";
    return 0;
}
