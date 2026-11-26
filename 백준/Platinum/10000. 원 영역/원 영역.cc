#include "bits/stdc++.h"
using namespace std;
using ll=long long;
#define fi first
#define se second
using pii=pair<ll,ll>;
using ppp=pair<pii,pii>;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    vector<pii>arr;
    for(int i=0;i<N;i++){
        ll x,r;cin>>x>>r;
        arr.push_back({x-r,-r});
        arr.push_back({x+r,r-1e18});
    }
    sort(arr.begin(),arr.end());
    
    stack<pii>stk;
    ll ans=0;
    for(auto p:arr){
        if(stk.empty()){
            stk.push({p.fi,0});
            continue;
        }
        if(p.se<-1e13){
            auto [x,r]=stk.top();stk.pop();
            if(x+r==p.fi)ans+=2;
            else ans+=1;
            if(!stk.empty())stk.top().se+=p.fi-x;
        }else{
            stk.push({p.fi,0});
        }
    }
    cout<<ans+1<<"\n";
    return 0;
}
