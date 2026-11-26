#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    while(1){
        int n;cin>>n;
        if(n==0)break;
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
    }
    return 0;
}
