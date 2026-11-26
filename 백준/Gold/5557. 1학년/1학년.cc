#include "bits/stdc++.h"
using namespace std;
using ll=long long;
#define fi first
#define se second

using ull=unsigned long long;
ull dp[103][22];
int main(){
    int N;cin>>N;
    int x0;cin>>x0;
    dp[1][x0]=1;
    for(int i=2;i<N;i++){
        int x;cin>>x;
        for(int j=0;j<=20;j++){
            if(dp[i-1][j]){
                if(j+x<=20)dp[i][j+x]+=dp[i-1][j];
                if(j-x>=0)dp[i][j-x]+=dp[i-1][j];
            }
        }
    }
    int res;cin>>res;
    cout<<dp[N-1][res]<<"\n";
    return 0;
}
