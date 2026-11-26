#include "bits/stdc++.h"
using namespace std;
using ll=long long;
#define fi first
#define se second
constexpr ll mod=1000000;
ll dp[5003];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    string s;cin>>s;
    s="!"+s;
    dp[0]=1;
    if(s[1]!='0')dp[1]=1;
    const int n=(int)s.size();
    for(int i=2;i<n;i++){
        int tmp=(s[i-1]-'0')*10+s[i]-'0';
        if(10<=tmp&&tmp<=26)dp[i]+=dp[i-2];
        if(s[i]!='0')dp[i]+=dp[i-1];
        dp[i]%=mod;
    }
    cout<<dp[n-1]<<"\n";
    return 0;
}
