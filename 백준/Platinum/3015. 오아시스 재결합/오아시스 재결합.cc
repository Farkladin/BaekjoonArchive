#include "bits/stdc++.h"
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    ll ans=0;
    stack<pair<ll,ll> >stk;
    for(int i=1;i<=N;i++){
        ll a;cin>>a;
        while(!stk.empty() && stk.top().first<a){
            ans+=stk.top().second;
            stk.pop();
        }
        if(!stk.empty() && stk.top().first>a)ans++;
        if(!stk.empty() && stk.top().first==a){
            auto TOP=stk.top(); stk.pop();
            ans+=TOP.second;
            TOP.second++;
            if(!stk.empty())ans++;
            stk.push(TOP);
        }else stk.push({a,1});
    }
    cout<<ans<<"\n";
    return 0;
}
