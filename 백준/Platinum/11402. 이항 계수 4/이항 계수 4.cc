#include "bits/stdc++.h"
using namespace std;
using ll = uint64_t;

ll C[3003][3003];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll N,K,M; cin>>N>>K>>M;
    C[0][0]=1;
    for(int i=1; i<=M; ++i){
        C[i][0]=1;
        for(int j=1; j<=i; ++j) C[i][j] = (C[i-1][j-1] + C[i-1][j]) %M;
    }
    
    ll ans=1;
    while(N || K){
        ans = ans*C[N%M][K%M] %M;
        N/=M; K/=M;
    }
    
    cout<<ans<<"\n";
    
    return 0;
}
