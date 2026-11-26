#include "bits/stdc++.h"
using namespace std;

double dp[(1<<20)|3], arr[22][22];
int8_t vis[(1<<20)|3];
int N;
double f(int bit){
    const int n = __builtin_popcount(bit);
    if(n >= N)return 1.0;
    double &ret = dp[bit];
    if(vis[bit])return ret;
    vis[bit]=1;
    for(int i=0; i<N; ++i){
        if(bit&(1<<i))continue;
        ret = max(ret, f(bit|(1<<i))*arr[i][n]);
    }
    
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin>>N;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            cin>>arr[i][j];
            arr[i][j]*=0.01;
        }
    }
    
    cout<<fixed<<setprecision(10)<<f(0)*100<<"\n";
    return 0;
}
