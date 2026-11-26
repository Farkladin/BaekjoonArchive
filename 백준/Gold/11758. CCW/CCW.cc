#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<ll,ll>;

inline int CCW(const pii &a,const pii &b,const pii &c){
    ll tmp=a.fi*b.se+b.fi*c.se+c.fi*a.se-a.se*b.fi-b.se*c.fi-c.se*a.fi;
    return tmp<0?-1:(tmp==0?0:1);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    pii a,b,c;cin>>a.fi>>a.se>>b.fi>>b.se>>c.fi>>c.se;
    cout<<CCW(a,b,c)<<"\n";
    return 0;
}
