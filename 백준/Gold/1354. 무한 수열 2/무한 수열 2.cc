#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
unordered_map<ll,ll>mp;
ll P,Q,X,Y;
ll f(ll N){
    if(N<=0)return 1;
    if(mp[N])return mp[N];
    mp[N]=f(N/P-X)+f(N/Q-Y);
    return mp[N];
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll N;cin>>N>>P>>Q>>X>>Y;
    mp[0]=1;
    cout<<f(N)<<"\n";
    return 0;
}
