#include "bits/stdc++.h"
using namespace std;

string S;
constexpr int mod = 10'007;
int dp[1003][1003];
int f(int l,int r){
    if(l>r)return 0;
    if(l==r)return 1;
    int &ret=dp[l][r];
    if(ret)return ret;
    ret=(ret+f(l+1,r)+f(l,r-1))%mod;
    if(S[l]!=S[r])ret=(ret+mod-f(l+1,r-1))%mod;
    else ret=(ret+1)%mod;
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin>>S;
    cout<<f(0,(int)S.size()-1)<<"\n";
    return 0;
}
