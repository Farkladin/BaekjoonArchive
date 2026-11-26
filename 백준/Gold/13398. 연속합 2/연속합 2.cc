#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
int dp[100003][2];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;cin>>n;
    int ans=-1e9;
    dp[1][1]=-1e9;
    for(int i=1;i<=n;i++){
        cin>>dp[i][0];
        dp[i][1]=dp[i][0];
        dp[i][0]+=max(0,dp[i-1][0]);
        if(i>=2)dp[i][1]+=max({0,dp[i-2][0],dp[i-1][1]});
        ans=max({ans,dp[i][0],dp[i][1]});
    }
    cout<<ans<<"\n";
    return 0;
}
