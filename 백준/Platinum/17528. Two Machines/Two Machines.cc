#include "bits/stdc++.h"
using namespace std;

constexpr int MAX = 250*250;
int dp[MAX+3];
pair<int,int> arr[253];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    fill(dp+1,dp+MAX+1,1e9);
    int n; cin>>n;
    for(int i=1; i<=n; ++i){
        cin>>arr[i].first>>arr[i].second;
        dp[0]+=arr[i].second;;
    }
    
    for(int i=1; i<=n; ++i){
        for(int j=MAX; j>=arr[i].first; --j){
            dp[j] = min(dp[j], dp[j-arr[i].first]-arr[i].second);
        }
    }
    
    int ans = 1e9;
    for(int i=0; i<=MAX; ++i) ans=min(ans,max(i,dp[i]));
    cout<<ans<<"\n";
    
    return 0;
}

