#include "bits/stdc++.h"
using namespace std;

int N,dp[10003][13],anc[10003][13],delta[10003][13];
int init[10003],target[10003];

int f(int i,int j){
    if(i>N)return 0;
    int &ret = dp[i][j];
    if(ret!=-1)return ret;
    ret=1e9;
    
    int p = (init[i]+j)%10;
    int L = f(i+1,(10+target[i]-init[i])%10) + ((10+target[i]-init[i])%10+10-j)%10;
    int R = f(i+1,j) + (10+p-target[i])%10;
    if(L<R){
        ret=L;
        anc[i][j] = (10+target[i]-init[i])%10;
        delta[i][j] = ((10+target[i]-init[i])%10+10-j)%10;
    }else{
        ret=R;
        anc[i][j] = j;
        delta[i][j] = -((10+p-target[i])%10);
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    
    cin>>N;
    for(int i=1; i<=N; ++i){
        char c; cin>>c;
        init[i] = c - '0';
    }
    
    for(int i=1; i<=N; ++i){
        char c; cin>>c;
        target[i] = c - '0';
    }
    
    memset(dp,-1,sizeof(dp));
    memset(anc,-1,sizeof(anc));
    cout<<f(1,0)<<"\n";
    /*
    for(int i=1,j=0; anc[i][j]!=-1; i++){
        cout<<i<<" "<<delta[i][j]<<"\n";
        j=anc[i][j];
    }
    */
    return 0;
}
