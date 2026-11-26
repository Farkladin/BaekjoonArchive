#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using lf=double;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;
using ppp=pair<pii,pii>;
int dp[10003];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,k;cin>>n>>k;
    fill(dp,dp+k+1,1e9);
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        if(x>k)continue;
        dp[x]=1;
        for(int j=x+1;j<=k;j++){
            dp[j]=min(dp[j-x]+1,dp[j]);
        }
    }
    if(dp[k]==1e9)dp[k]=-1;
    cout<<dp[k]<<"\n";
    return 0;
}

