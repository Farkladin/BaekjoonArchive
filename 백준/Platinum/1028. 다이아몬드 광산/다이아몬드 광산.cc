#include "bits/stdc++.h"
using namespace std;

char arr[1003][1003];
struct Type{
    int a,b,c,d;
}dp[1003][1003];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int R,C;cin>>R>>C;
    for(int i=1;i<=R;++i){
        for(int j=1;j<=C;++j)cin>>arr[i][j];
    }
    
    int ans=0;
    for(int i=1;i<=R;++i){
        for(int j=1;j<=C;++j){
            if(arr[i][j]=='1'){
                ans=1;
                dp[i][j].a=dp[i-1][j-1].a+1;
                dp[i][j].b=dp[i-1][j+1].b+1;
            }
            
            if(arr[R-i+1][j]=='1'){
                dp[R-i+1][j].c=dp[R-i+2][j-1].c+1;
                dp[R-i+1][j].d=dp[R-i+2][j+1].d+1;
            }
        }
    }
    
    for(int i=1;i<=R;++i){
        for(int j=1;j<=C;++j){
            int c=dp[i][j].c, d=dp[i][j].d;
            int x=min(c,d)-1;
            for(int k=1; i+k+k<=R && k<=x; ++k){
                if(dp[i+k+k][j].a>=k+1 && dp[i+k+k][j].b>=k+1){
                    ans=max(ans,k+1);
                }
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}
