#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;

vector<int>CPF(string &s){
    const int n=(int)s.size();
    vector<int>nxt(n);
    for(int i=1,j=0;i<n;i++){
        while(j>0&&s[i]!=s[j])j=nxt[j-1];
        if(s[i]==s[j])nxt[i]=++j;
    }
    return nxt;
}

int KMP(string &T,string &P){
    vector<int>nxt=CPF(P);
    const int n=(int)T.size(),m=(int)P.size();
    int ans=0;
    for(int i=0,j=0;i<n;i++){
        if(j>m)j=nxt[j-1];
        while(j>0&&T[i]!=P[j])j=nxt[j-1];
        if(T[i]==P[j])j++;
        if(j==m)ans++;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    string A,B;cin>>A>>B;
    string T=B+B;T.pop_back();
    cout<<KMP(T,A)<<"\n";
    return 0;
}
