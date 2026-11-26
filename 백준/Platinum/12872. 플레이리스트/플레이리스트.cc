#include "bits/stdc++.h"
using namespace std;

using ll = long long;
constexpr ll mod = 1'000'000'007;

ll C[103][103], F[103];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    C[0][0]=1;
    F[0]=1;
    for(int i=1; i<=100; ++i){
        C[i][0]=1;
        F[i] = F[i-1]*i %mod;
        for(int j=1; j<=i;++j){
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) %mod;
        }
    }
    
    int N, M, P; cin>>N>>M>>P;
    ll ans=0, sign=1;
    for(ll n=N; n>=M; --n){
        ll cur = 0;
        if(n>M){
            cur = C[n][M+1] * F[M+1] %mod;
            
            for(int i=M+2; i<=P; ++i){
                cur = cur*(n-M) %mod;
            }
        }else{
            if(n==P)cur = C[n][P]*F[P];
        }
        ans = (ans + mod + (C[N][n]*cur %mod *sign)) %mod;
        sign *= -1;
    }
    
    cout<<ans<<"\n";
    return 0;
}
