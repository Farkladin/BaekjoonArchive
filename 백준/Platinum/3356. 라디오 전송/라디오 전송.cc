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
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int L;cin>>L;
    string s;cin>>s;
    cout<<L-cpf(s).back()<<"\n";
    return 0;
}
