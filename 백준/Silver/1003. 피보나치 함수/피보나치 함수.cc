#include "bits/stdc++.h"
using namespace std;
using ll=long long;
ll dp[44]={0,1};
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    for(int i=2;i<=40;i++)dp[i]=dp[i-1]+dp[i-2];
    int T;cin>>T;
    while(T--){
        int N;cin>>N;
        if(N==1)cout<<"0 1\n";
        else if(N==0)cout<<"1 0\n";
        else cout<<dp[N-1]<<" "<<dp[N]<<"\n";
    }
    return 0;
}
