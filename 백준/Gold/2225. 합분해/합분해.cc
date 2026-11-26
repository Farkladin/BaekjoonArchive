#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using lf=double;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;
using ppp=pair<pii,pii>;
constexpr ll mod=1e9;
ll dp[203][203];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,K;cin>>N>>K;
    for(int i=0;i<=K;i++)dp[0][i]=1;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=K;j++){
            for(int k=0;k<=i;k++){
                dp[i][j]+=dp[i-k][j-1];
            }
            dp[i][j]%=mod;
        }
    }
    cout<<dp[N][K]<<"\n";
    return 0;
}

