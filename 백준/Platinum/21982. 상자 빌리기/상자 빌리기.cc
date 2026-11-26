#include "bits/stdc++.h"
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;

void solve(){
    int n, X; cin>>n>>X;
    ll hs, ha, hb, hc, ws, wa, wb, wc;
    cin>>hs>>ha>>hb>>hc>>ws>>wa>>wb>>wc;
    
    ll h = hs%hc + 1, w = ws%wc + 1;
    deque<pii>dq;
    dq.push_back(pii{h,h*w});
    
    ll ans = -1;
    for(int i=1; i<n; ++i){
        h = h + 1 + (h*ha + hb)%hc;
        w = (w*wa + wb)%wc + 1;
        const ll cur = h*w;
        
        while(!dq.empty() && h-dq.front().first > X) dq.pop_front();
        
        if(!dq.empty()) ans = max(ans, dq.front().second + cur);
        
        while(!dq.empty() && dq.back().second < cur) dq.pop_back();
        dq.push_back(pii{h,cur});
    }
    
    cout<<ans<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int T;cin>>T;
    while(T--) solve();
    return 0;
}
