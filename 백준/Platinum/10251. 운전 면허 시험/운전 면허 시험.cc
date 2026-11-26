#include "bits/stdc++.h"
using namespace std;

int dp[103][103][203][2],hrr[111][111],wrr[111][111];

void solve(){
    memset(dp,-1,sizeof(dp));
    int M,N,L,G; cin>>M>>N>>L>>G;
    for(int i=1; i<=M; ++i){
        for(int j=2; j<=N; ++j){
            cin>>wrr[i][j];
        }
    }
    for(int i=2; i<=M; ++i){
        for(int j=1; j<=N; ++j){
            cin>>hrr[i][j];
        }
    }
    
    fill(&(dp[0][0][0][0]),&(dp[0][0][0][0])+103*103*203*2,1e9);
    dp[1][1][0][0]=0;
    dp[1][1][0][1]=0;
    for(int i=1; i<=M; ++i){
        for(int j=1; j<=N; ++j){
            dp[i][j][0][0] = min(dp[i][j][0][0],dp[i-1][j][0][0] + hrr[i][j]);
            dp[i][j][0][1] = min(dp[i][j][0][1],dp[i][j-1][0][1] + wrr[i][j]);
            for(int k=1; k<=200; ++k){
                dp[i][j][k][0] = min(dp[i][j][k-1][1], dp[i-1][j][k][0]+hrr[i][j]);
                dp[i][j][k][1] = min(dp[i][j][k-1][0], dp[i][j-1][k][1]+wrr[i][j]);
            }
        }
    }
    
    for(int k=0; k<=200; ++k){
        if(dp[M][N][k][0]<=G || dp[M][N][k][1]<=G){
            cout<<k + L*(M+N-2)<<"\n";
            return;
        }
    }
    cout<<"-1\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;cin>>T;
    while(T--)solve();
    return 0;
}

