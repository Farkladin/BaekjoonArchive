#include "bits/stdc++.h"
using namespace std;
using ll=long long;
ll dp[10003];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    dp[0]=1;
    for(int i=1;i<=10000;i++){
        dp[i]+=dp[i-1];
    }
    for(int i=2;i<=10000;i++){
        dp[i]+=dp[i-2];
    }
    for(int i=3;i<=10000;i++){
        dp[i]+=dp[i-3];
    }
    
    int T;cin>>T;
    while(T--){
        int n;cin>>n;
        cout<<dp[n]<<"\n";
    }
    return 0;
}
