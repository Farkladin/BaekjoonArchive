#include "bits/stdc++.h"
using namespace std;
using ll = long long;

ll dp[103][2]={{}, {1}, {1,1}, {2,2}}, C[103][103];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    C[0][0]=1;
    for(int i=1;i<=100;++i){
        C[i][0]=1;
        for(int j=1;j<=i;++j){
            C[i][j]=(C[i-1][j] + C[i-1][j-1]);
        }
    }
    
    int N=20;
    
    for(int i=4; i<=N; ++i){
        if(i&1){
            dp[i][1]=2*dp[i-1][0];
        }else{
            dp[i][0]=dp[i-1][0];
            dp[i][1]=dp[i-1][0];
        }
        
        for(int j=1; j+1<i; ++j){
            const ll &c = C[i-1][j];
            if(j&1){
                dp[i][0] = (dp[i][0] + c*dp[j][0]*dp[i-j-1][0]);
            }else{
                dp[i][1] = (dp[i][1] + c*dp[j][1]*dp[i-j-1][0]);
            }
        }
    }
    
    int T; cin>>T;
    while(T--){
        cin>>N;
        cout<<(dp[N][0]+dp[N][1])<<"\n";
    }
    return 0;
}
