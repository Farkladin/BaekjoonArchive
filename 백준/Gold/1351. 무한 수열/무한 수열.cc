#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
map<ll,ll>mp;
ll P,Q;
ll f(ll N){
    if(mp[N])return mp[N];
    mp[N]=f(N/P)+f(N/Q);
    return mp[N];
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll N;cin>>N>>P>>Q;
    mp[0]=1;
    cout<<f(N)<<"\n";
    return 0;
}
