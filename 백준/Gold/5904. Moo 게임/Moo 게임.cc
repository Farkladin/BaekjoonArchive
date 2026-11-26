#include "bits/stdc++.h"
using namespace std;
using ll=long long;

constexpr array<ll,30> preCom(){
    array<ll,30>dp;
    dp[0]=3;
    for(int i=1;i<30;i++){
        dp[i]=dp[i-1]*2+i+3;
    }
    return dp;
}
constexpr array<ll,30>dp=preCom();

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll N;cin>>N;
    loop:
    for(int i=0;i<30;i++){
        if(N<=dp[i]){
            if(i==0){
                if(N==1)cout<<"m\n";
                else cout<<"o\n";
                return 0;
            }if(N>dp[i-1]+i+3){
                N-=dp[i-1]+i+3;
                goto loop;
            }else if(N>dp[i-1]){
                if(N==dp[i-1]+1)cout<<"m\n";
                else cout<<"o\n";
                return 0;
            }
        }
    }
    goto loop;
    return 1;
}
