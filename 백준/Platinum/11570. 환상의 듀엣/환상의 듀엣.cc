#include "bits/stdc++.h"
using namespace std;

using ll = long long;
ll dp[2003][2003];
ll arr[2003];
int N;

ll f(int i,int j){
    int nxt=max(i,j)+1;
    ll &ret=dp[i][j];
    if(ret!=-1)return ret;
    if(nxt>N)return 0;
    
    ll c1 = f(nxt,j) + (i==0?0:abs(arr[i]-arr[nxt])), c2 = f(i,nxt) + (j==0?0:abs(arr[j]-arr[nxt]));
    ret = min(c1,c2);
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>N;
    for(int i=1;i<=N;++i) cin>>arr[i];
    
    memset(dp,-1,sizeof(dp));
    cout<<f(0,0)<<"\n";
    
    return 0;
}
