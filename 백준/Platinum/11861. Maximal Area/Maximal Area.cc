#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using lf=double;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;
using ppp=pair<pii,pii>;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;cin>>n;
    vector<ll>arr(n+3);
    for(int i=1;i<=n;i++)cin>>arr[i];
    stack<ll>stk;
    ll ans=0;
    for(ll i=1;i<=n;i++){
        while(!stk.empty()&&arr[stk.top()]>arr[i]){
            ll j=stk.top();stk.pop();
            if(!stk.empty())ans=max(ans,arr[j]*(i-stk.top()-1));
            else ans=max(ans,arr[j]*(i-1));
        }
        stk.push(i);
    }
    while(!stk.empty()){
        ll j=stk.top();stk.pop();
        if(!stk.empty())ans=max(ans,arr[j]*(n-stk.top()));
        else ans=max(ans,arr[j]*n);
    }
    cout<<ans<<"\n";
    return 0;
}

