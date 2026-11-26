#include "bits/stdc++.h"
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int T;cin>>T;
    while(T--){
        ll x,y;cin>>x>>y;
        ll t=y-x,ans=0;
        for(;(ans/2)*(ans/2+1)+(ans&1)*(ans/2+1)<t;ans++);
        cout<<ans<<"\n";
    }
    return 0;
}
