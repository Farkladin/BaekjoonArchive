#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;
ll dp[44][4],arr[44];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N, K; cin>>N>>K;
    dp[1][0]=1;
    arr[1]=1;
    arr[0]=1;
    for(int i=2; i<=N; ++i){
        dp[i][0]=dp[i-1][0]+dp[i-1][1];
        dp[i][1]=dp[i-1][0];
        arr[i]=dp[i][0]+dp[i][1];
    }
    
    ll ans=arr[K-1]*arr[N-K];
    
    for(int i=1; i<K; ++i){
        for(int j=1; j<=i; ++j){
            ans+= arr[N-K]*arr[j-1]*arr[K-i-1];
        }
        for(int j=i+1; j<K; ++j){
            ans+= arr[N-K]*arr[i-1]*arr[K-j-1];
        }
    }
    
    for(int i=1; i<=N-K; ++i){
        for(int j=1; j<=i; ++j){
            ans+= arr[K-1]*arr[j-1]*arr[N-K-i];
        }
        for(int j=i+1; j<=N-K; ++j){
            ans+= arr[K-1]*arr[i-1]*arr[N-K-j];
        }
    }
    
    cout<<ans<<"\n";
    return 0;
}
