#include "bits/stdc++.h"
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,K;cin>>N>>K;
    ll ans=1;
    for(int i=N;i>N-K;i--)ans*=i;
    for(int i=1;i<=K;i++)ans/=i;
    cout<<ans<<"\n";
    return 0;
}
