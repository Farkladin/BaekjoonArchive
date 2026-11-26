#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
constexpr ll mod=1e9+7;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll H,x;cin>>H>>x;
    ll ans=0;
    stack<ll>stk;
    while(H--){
        ll c;cin>>c;
        stk.push(c);
    }
    while(!stk.empty()){
        ans=(ans*x+stk.top())%mod;
        stk.pop();
    }
    cout<<ans*x%mod<<"\n";
    return 0;
}
