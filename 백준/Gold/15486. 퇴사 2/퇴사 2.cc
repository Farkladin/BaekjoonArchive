#include "bits/stdc++.h"
using namespace std;
using ll=long long;
int dp[1'530'000];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    for(int i=1;i<=N;i++){
        int T,P;cin>>T>>P;
        dp[i+T]=max(dp[i+T],dp[i]+P);
        dp[i+1]=max(dp[i],dp[i+1]);
    }
    cout<<dp[N+1]<<"\n";
    return 0;
}
