#include "bits/stdc++.h"
using namespace std;
using ll=long long;
int dp[10003];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int T;cin>>T;
    while(T--){
        int N;cin>>N;
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        while(N--){
            int x;cin>>x;
            for(int i=0;i+x<=10000;i++){
                dp[i+x]+=dp[i];
            }
        }
        int M;cin>>M;
        cout<<dp[M]<<"\n";
    }
    return 0;
}
