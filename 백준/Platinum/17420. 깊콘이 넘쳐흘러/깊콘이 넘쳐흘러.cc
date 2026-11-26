#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<ll,ll>;
map<ll,vector<ll> >mp;
ll arr[100003];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int N; cin>>N;
    for(int i=1; i<=N; ++i) cin>>arr[i];
    for(int i=1; i<=N; ++i){
        ll A=arr[i],B; cin>>B;
        mp[B].push_back(A);
    }
    
    ll mx=0, ans=0;
    for(auto &[B,vec]:mp){
        ll cur=0;
        for(auto A:vec){
            ll target = max(mx,B);
            if(A<target){
                ll k = (target-A+29)/30;
                ans+=k;
                A+=k*30;
            }
            cur=max(cur,A);
        }
        mx=max(mx,cur);
    }
    
    cout<<ans<<"\n";
    
    return 0;
}
