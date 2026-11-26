#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;

vector<int>CPF(string &s){ // Compute Prefix Function
    const int n=(int)s.size();
    vector<int>nxt(n);
    for(int i=1,j=0;i<n;i++){
        while(j>0&&s[i]!=s[j])j=nxt[j-1];
        if(s[i]==s[j])nxt[i]=++j;
    }
    return nxt;
}

vector<int>KMP(string &T,string &P){
    vector<int>next=CPF(P),ans;
    const int n=(int)T.size(),m=(int)P.size();
    for(int i=0,j=0;i<n;i++){
        while(j>0&&T[i]!=P[j])j=next[j-1];
        if(T[i]==P[j])j++;
        if(j==m)ans.push_back(i-m+2); // Position where P appears in T
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    while(1){
        string s;cin>>s;
        if(s==".")break;
        auto x=CPF(s);
        const int n=(int)s.size();
        if(n%(n-x.back())==0){
            cout<<n/(n-x.back())<<"\n";
        }else cout<<"1\n";
    }
    return 0;
}
