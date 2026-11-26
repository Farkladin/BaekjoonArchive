#include "bits/stdc++.h"
using namespace std;
using ll=long long;
vector<int>cpf(string &s){
    const int n=(int)s.size();
    vector<int>nxt(n);
    for(int i=1,j=0;i<n;i++){
        while(j>0&&s[i]!=s[j])j=nxt[j-1];
        if(s[i]==s[j])nxt[i]=++j;
    }
    return nxt;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;cin>>n;
    string S;cin>>S;
    auto nxt=cpf(S);
    ll ans=0;
    vector<ll>dp(n+3);
    for(int i=0;i<n;i++){
        if(nxt[i]){
            int j=nxt[i]-1;
            if(!dp[j])dp[i]=j+1;
            else dp[i]=dp[j];
            ans+=i-dp[i]+1;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
