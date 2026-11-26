#include "bits/stdc++.h"
using namespace std;
using ll=long long;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N,D;cin>>N>>D;
    deque<pair<int,ll> >dq;
    ll ans=-1e18;
    for(int i=1;i<=N;++i){
        ll K;cin>>K;
        if(i>D && dq.front().first<i-D)dq.pop_front();
        
        ll cur = K;
        if(!dq.empty()) cur = max(cur, dq.front().second+K);
        while(!dq.empty() && dq.back().second<cur)dq.pop_back();
        dq.push_back(pair<int,ll>{i,cur});
        
        
        ans=max(ans,cur);
    }
    
    cout<<ans<<"\n";
    
    return 0;
}
