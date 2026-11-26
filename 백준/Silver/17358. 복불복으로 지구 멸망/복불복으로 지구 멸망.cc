#include "bits/stdc++.h"
using namespace std;
using ll=long long;
constexpr ll mod=1e9+7;
ll dp[100003];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    dp[2]=1;
    for(int i=4;i<=N;i+=2){
        dp[i]=(dp[i]+dp[i-2]*(i-1)%mod)%mod;
    }
    cout<<dp[N]<<"\n";
    return 0;
}
