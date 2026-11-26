#include "bits/stdc++.h"
using namespace std;

int N,arr[20][20],P,dp[(1<<16)|3];
int f(int bit){
    int &ret=dp[bit];
    if(ret!=-1)return ret;
    if(__builtin_popcount(bit)>=P)return 0;
    ret=1e9;
    for(int i=0;i<N;i++){
        if(!(bit&(1<<i))){
            for(int j=0;j<N;j++){
                if(bit&(1<<j)){
                    ret=min(ret,f(bit|(1<<i))+arr[j][i]);
                }
            }
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)cin>>arr[i][j];
    }
    string s;cin>>s;
    int bit=0;
    for(int i=0;i<N;i++){
        if(s[i]=='Y')bit|=(1<<i);
    }
    cin>>P;
    memset(dp,-1,sizeof(dp));
    int ans=f(bit);
    if(ans==1e9)ans=-1;
    cout<<ans<<"\n";
    
    return 0;
}
