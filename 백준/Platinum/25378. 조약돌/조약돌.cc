#include "bits/stdc++.h"
using namespace std;

int arr[2503],dp[2503];
int8_t r[2503][2503];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int N; cin>>N;
    for(int i=1; i<=N; ++i){
        cin>>arr[i];
        int k=arr[i];
        for(int j=i-1; k>=0 && j>0; --j){
            k=arr[j]-k;
            if(k==0){
                r[i][j]=1;
                break;
            }
        }
    }
    
    for(int i=1; i<=N; ++i){
        dp[i]=dp[i-1]+1;
        for(int j=1; j<i; ++j){
            if(r[i][j])dp[i]=min(dp[i],dp[j-1]+i-j);
        }
    }
    
    cout<<dp[N]<<"\n";
    
    return 0;
}
