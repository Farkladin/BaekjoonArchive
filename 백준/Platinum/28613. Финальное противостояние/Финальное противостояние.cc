#include "bits/stdc++.h"
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;

void solve(){
    int n; ll m1,m2;
    cin>>n>>m1>>m2;
    
    ll ans=0;
    deque<pii>dq11,dq12,dq21,dq22;
    for(ll i=1,j=1,k=1; i<=n; ++i){
        ll l,r; cin>>l>>r;
        
        while(!dq11.empty() && dq11.back().second < l) dq11.pop_back();
        while(!dq12.empty() && dq12.back().second > r) dq12.pop_back();
        dq11.push_back(pii{i,l});
        dq12.push_back(pii{i,r});
        
        while(j<=i && max(dq12.front().second-dq11.front().second, 0LL) < m1){
            if(dq12.front().first<=j) dq12.pop_front();
            if(dq11.front().first<=j) dq11.pop_front();
            ++j;
        }
        
        
        while(!dq21.empty() && dq21.back().second < l) dq21.pop_back();
        while(!dq22.empty() && dq22.back().second > r) dq22.pop_back();
        dq21.push_back(pii{i,l});
        dq22.push_back(pii{i,r});
        
        while(k<=i && max(dq22.front().second-dq21.front().second, 0LL) <= m2){
            if(dq22.front().first<=k) dq22.pop_front();
            if(dq21.front().first<=k) dq21.pop_front();
            ++k;
        }
        
        
        ans+=k-j;
    }
    
    cout<<ans<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    solve();
    return 0;
}
