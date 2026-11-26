#include "bits/stdc++.h"
using namespace std;

vector<int>CPF(string &s){ // Compute Prefix Function
    const int n=(int)s.size();
    vector<int>nxt(n);
    for(int i=1,j=0;i<n;++i){
        while(j>0&&s[i]!=s[j])j=nxt[j-1];
        if(s[i]==s[j])nxt[i]=++j;
    }
    return nxt;
}


int in[256];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    
    string s;cin>>s;
    if(s.size()==1){
        cout<<"0 1\n";
        return 0;
    }
    
    for(char c:s) in[c]=1;
    vector<int>cpf(CPF(s));
    const int k = (int)s.size() - cpf.back(), n=(int)s.size();
    
    s=s+s;
    int mn=1e9, rpt=0;
    for(int i=0; i<k; ++i){
        int cur1=0,cur2=0;
        for(char c='a'; c<='z'; ++c){
            cur1 = max(cur1,abs(c-s[i])*in[c]);
            cur2 = max(cur2,abs(c-s[i+n-1])*in[c]);
        }
        if(cur1+cur2<mn){
            rpt=0;
            mn=cur1+cur2;
        }
        if(cur1+cur2 == mn)rpt++;
    }
    
    cout<<mn<<" "<<rpt<<"\n";
    return 0;
}
