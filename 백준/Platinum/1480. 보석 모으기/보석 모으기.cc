#include "bits/stdc++.h"
using namespace std;
int dp[12][22][(1<<13)|3], W[15];
int N,M,C;
int f(int m, int c, int used){
    int &ret = dp[m][c][used];
    if(ret!=-1)return ret;
    if(__builtin_popcount(used)==N)return 0;
    
    for(int i=0; i<N; ++i){
        if(used&(1<<i))continue;
        int nxtUsed = used|(1<<i);
        ret = max(ret, f(m,c,nxtUsed));
        if(c+W[i]<=C){
            ret = max(ret, f(m,c+W[i],nxtUsed)+1);
        }else if(W[i]<=C && m<M){
            ret = max(ret, f(m+1,W[i],nxtUsed)+1);
        }
    }
    
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>N>>M>>C;
    for(int i=0; i<N; ++i) cin>>W[i];
    
    memset(dp,-1,sizeof(dp));
    cout<<f(1,0,0)<<"\n";
    
    return 0;
}
