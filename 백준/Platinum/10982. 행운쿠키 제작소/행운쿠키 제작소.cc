#include "bits/stdc++.h"
using namespace std;

int a[1003], b[1003], dp[50005];
void solve(){
    int N; cin>>N;
    fill(dp,dp+50001,1e9);
    dp[0]=0;
    for(int i=1; i<=N; ++i){
        cin>>a[i]>>b[i];
        dp[0]+=b[i];
    }
    
    for(int i=1; i<=N; ++i){
        for(int j=50000; j>=a[i]; --j){
            if(dp[j-a[i]] < 1e9)dp[j]=min(dp[j-a[i]]-b[i],dp[j]);
        }
    }
    
    int ans=1e9;
    for(int i=0; i<=50000; ++i) ans=min(ans,max(dp[i],i));
    
    cout<<ans<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int T;cin>>T;
    while(T--)solve();
    return 0;
}
