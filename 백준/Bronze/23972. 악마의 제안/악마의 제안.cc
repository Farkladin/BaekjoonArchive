#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
using ppp=pair<pii,pii>;

int main(){
    ll K,N;cin>>K>>N;
    if(N==1)cout<<"-1\n";
    // x*(N-1)>=K*N/(N-1)
    // (x-K)*N==x
    else cout<<(K*N+N-2)/(N-1)<<"\n";
    return 0;
}
