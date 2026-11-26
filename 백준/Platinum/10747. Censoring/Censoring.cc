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

string sol10747(string &S,string &T){
    vector<int>nxt(cpf(T));
    stack<int>memo;
    memo.push(1);
    string ans;
    const int n=(int)S.size(),m=(int)T.size();
    for(int i=0,j=0;i<n;i++){
        ans.push_back(S[i]);
        while(j>0&&S[i]!=T[j])j=nxt[j-1];
        if(S[i]==T[j])j++;
        memo.push(j);
        if(j==m){
            for(int k=0;k<m;k++){
                ans.pop_back();
                memo.pop();
            }
            j=memo.top();
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    string S,T;cin>>S>>T;
    cout<<sol10747(S, T)<<"\n";
    return 0;
}
