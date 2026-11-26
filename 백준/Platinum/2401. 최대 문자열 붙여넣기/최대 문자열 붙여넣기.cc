#include "bits/stdc++.h"
using namespace std;

vector<int>cpf(string &s){
    const int n=(int)s.size();
    vector<int>nxt(n);
    for(int i=1,j=0;i<n;i++){
        while(j>0&&s[i]!=s[j])j=nxt[j-1];
        if(s[i]==s[j])nxt[i]=++j;
    }
    return nxt;
}

bool arr[100003][503];
void kmp(string &T,string &P,const int &idx){
    vector<int>nxt=cpf(P),ans;
    const int n=(int)T.size(),m=(int)P.size();
    for(int i=0,j=0;i<n;i++){
        while(j>0&&T[i]!=P[j])j=nxt[j-1];
        if(T[i]==P[j])j++;
        if(j==m){
            arr[i+1][idx]=true;
            j=nxt[j-1];
        }
    }
}
int dp[100003],ss[503];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    string T;cin>>T;
    int N;cin>>N;
    for(int i=1;i<=N;i++){
        string s;cin>>s;
        kmp(T,s,i);
        ss[i]=(int)s.size();
    }
    const int n=(int)T.size();
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1];
        for(int j=1;j<=N;j++){
            if(arr[i][j]){
                dp[i]=max(dp[i-ss[j]]+ss[j],dp[i]);
            }
        }
    }
    cout<<dp[n]<<"\n";
    return 0;
}
