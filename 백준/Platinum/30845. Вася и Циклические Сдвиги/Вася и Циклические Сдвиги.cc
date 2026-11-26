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


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    
    string s;cin>>s;
    vector<int>cpf(CPF(s));
    const int n=(int)s.size();
    if(n%(n-cpf.back())==0)cout<<n/(n-cpf.back())<<"\n";
    else cout<<"1\n";
    
    return 0;
}
