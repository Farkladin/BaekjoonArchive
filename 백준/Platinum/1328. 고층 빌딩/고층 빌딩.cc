#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;
constexpr ll mod = 1000000007;
ll D[103][103][103];
ll f(int n,int l,int r){
    if(n<l || n<r || l<=0 || r<=0 || n<=0) return 0;
    ll &ret = D[n][l][r];
    if(ret!=-1)return ret;
    ret = ( f(n-1,l,r)*(n-2)%mod + f(n-1,l-1,r) + f(n-1,l,r-1) )%mod;
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,L,R;cin>>N>>L>>R;
    memset(D,-1,sizeof(D));
    D[1][1][1]=1;
    D[2][1][1]=0;
    D[2][1][2]=1;
    D[2][2][1]=1;
    cout<<f(N,L,R)<<"\n";
    return 0;
}
