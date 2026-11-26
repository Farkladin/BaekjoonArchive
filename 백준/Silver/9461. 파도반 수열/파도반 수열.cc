#include "bits/stdc++.h"
using namespace std;
using ll=long long;
ll dp[103]={0,1,1,1,2,2,3,4,5,7,9};
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    for(int i=11;i<=100;i++)dp[i]=dp[i-1]+dp[i-5];
    int T;cin>>T;
    while(T--){
        int N;cin>>N;
        cout<<dp[N]<<"\n";
    }
    return 0;
}
