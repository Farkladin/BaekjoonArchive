#include "bits/stdc++.h"
using namespace std;
using ll=long long;
constexpr ll mod=1e9+7;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll a=1,b=1;
    int n;cin>>n;
    for(int i=3;i<=n;i++){
        ll tmp=b;
        b=(a+b)%mod;
        a=tmp;
    }
    cout<<b<<" "<<n-2<<"\n";
    return 0;
}
