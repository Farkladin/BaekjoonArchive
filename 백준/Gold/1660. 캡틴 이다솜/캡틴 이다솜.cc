#include "bits/stdc++.h"
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    vector<int>dp(N+3,1e9);
    dp[0]=0;
    for(int k=1,t=1;k<=N;t++,k+=(t*(t+1))>>1){
        for(int i=0;i+k<=N;i++){
            dp[i+k]=min(dp[i+k],dp[i]+1);
        }
    }
    cout<<dp[N]<<"\n";
    return 0;
}
