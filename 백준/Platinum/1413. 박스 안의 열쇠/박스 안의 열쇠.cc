#include "bits/stdc++.h"
using namespace std;
using ll=uint64_t;
ll facto[22]={1},dp[22][22];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    for(ll i=1;i<=20;++i)facto[i]=facto[i-1]*i;
    
    int N,M; cin>>N>>M;
    dp[0][0]=1;
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=i; ++j){
            dp[i][j] = dp[i-1][j-1] + (i-1)*dp[i-1][j];
        }
    }
    
    ll sum=0;
    for(int i=1; i<=M; ++i) sum+=dp[N][i];
    
    ll GCD = gcd(sum,facto[N]);
    cout<<sum/GCD<<"/"<<facto[N]/GCD<<"\n";
    
    return 0;
}
