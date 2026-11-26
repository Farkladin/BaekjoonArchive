#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;

vector<int>CPF(string &s){
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
    string S;ll K;cin>>S>>K;
    vector<int>nxt=CPF(S);
    const ll n=(ll)S.size();
    cout<<n+(n-nxt.back())*(K-1)<<"\n";
    return 0;
}
