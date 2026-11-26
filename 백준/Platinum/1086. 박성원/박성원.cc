#include "bits/stdc++.h"
using namespace std;
using ll=long long;
ll dp[(1<<15)|3][103];
int arr[20],len[20],N,K;

ll f(int bit,int mod){
    ll &ret=dp[bit][mod];
    if(ret!=-1)return ret;
    if(bit+1==(1<<N))return mod==0;
    ret=0;
    for(int i=0;i<N;i++){
        if(!(bit&(1<<i))){
            int newmod = (mod*len[i] + arr[i])%K;
            ret += f(bit|(1<<i),newmod);
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin>>N;
    vector<string>nums(N);
    for(auto &s:nums)cin>>s;
    cin>>K;
    for(int i=0;i<N;i++){
        len[i]=1;
        for(auto c:nums[i]){
            arr[i]=(arr[i]*10+c-'0')%K;
            len[i]=len[i]*10%K;
        }
    }
    ll facto=1;
    for(ll i=1;i<=N;i++)facto*=i;
    
    memset(dp,-1,sizeof(dp));
    ll nu=f(0,0);
    ll GCD=gcd(nu,facto);
    cout<<nu/GCD<<"/"<<facto/GCD<<"\n";
    return 0;
}
