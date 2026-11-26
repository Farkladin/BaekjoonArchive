#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;cin>>n;
    vector<pair<ll,ll> >vp(n);
    for(auto &p:vp)cin>>p.fi>>p.se;
    int m;cin>>m;
    while(m--){
        int cnt=-1;
        int i;ll d;cin>>i>>d;
        for(auto &p:vp){
            if(d*d>=(p.fi-vp[i-1].fi)*(p.fi-vp[i-1].fi)+(p.se-vp[i-1].se)*(p.se-vp[i-1].se)){
                cnt++;
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}
