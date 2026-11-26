#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll G;cin>>G;
    bool flag=false;
    for(ll i=1;i<=2*G;i++){
        if(i*i<=G)continue;
        ll x=sqrt(i*i-G)+1e-6;
        if(x*x==i*i-G){
            cout<<i<<"\n";
            flag=true;
        }
    }
    if(!flag)cout<<"-1\n";
    return 0;
}
