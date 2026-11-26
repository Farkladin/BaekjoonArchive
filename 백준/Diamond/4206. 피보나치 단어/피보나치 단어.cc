#include "bits/stdc++.h"
using namespace std;
using ull=uint64_t;

vector<int>cpf(string &s){
    const int n=(int)s.size();
    vector<int>nxt(n);
    for(int i=1,j=0;i<n;i++){
        while(j>0&&s[i]!=s[j])j=nxt[j-1];
        if(s[i]==s[j])nxt[i]=++j;
    }
    return nxt;
}

int kmp(string &T,string &P,vector<int>&nxt){
    const int n=(int)T.size(),m=(int)P.size();
    int cnt=0;
    for(int i=0,j=0;i<n;i++){
        while(j>0&&T[i]!=P[j])j=nxt[j-1];
        if(T[i]==P[j])j++;
        if(j==m){
            cnt++;
            j=nxt[j-1];
        }
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    vector<string>fib{"0","1","10"};
    while(fib.back().size()<=200000){
        const int k=(int)fib.size();
        fib.push_back(fib[k-1]+fib[k-2]);
    }
    int n,tc=0;
    while(cin>>n){
        tc++;
        string s;cin>>s;
        vector<int>pf=cpf(s);
        int idx=0;
        const size_t m=(int)s.size();
        for(;fib[idx].size()<m;idx++);
        string &tmp1=fib[idx],&tmp2=fib[idx+1];
        string pref=fib[idx].substr(0,m-1),suf1=tmp1.substr(tmp1.size()-m+1,m-1),suf2=tmp2.substr(tmp2.size()-m+1,m-1);
        ull odd,even;
        string x=suf1+pref,y=suf2+pref;
        if(idx&1){
            odd=kmp(y,s,pf);
            even=kmp(x,s,pf);
        }else{
            odd=kmp(x,s,pf);
            even=kmp(y,s,pf);
        }
        
        vector<ull>dp(203);
        dp[idx]=kmp(fib[idx],s,pf);
        dp[idx+1]=kmp(fib[idx+1],s,pf);
        for(int i=idx+2;i<=n;i++){
            if(i&1)dp[i]=dp[i-1]+dp[i-2]+odd;
            else dp[i]=dp[i-1]+dp[i-2]+even;
        }
        cout<<"Case "<<tc<<": "<<dp[n]<<"\n";
    }
    return 0;
}
