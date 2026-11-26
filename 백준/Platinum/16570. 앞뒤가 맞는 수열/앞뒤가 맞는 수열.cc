#include "bits/stdc++.h"
using namespace std;
using ll=long long;
vector<int>cpf(const vector<ll> &s){
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
    int N;cin>>N;
    vector<ll>A(N);
    for(ll &a:A)cin>>a;
    reverse(A.begin(),A.end());

    auto pf=cpf(A);
    ll mx=-1,cnt=0;
    for(auto &x:pf){
        if(x>mx){
            mx=x;
            cnt=0;
        }
        if(x==mx)cnt++;
    }
    
    if(mx==0)cout<<"-1\n";
    else cout<<mx<<" "<<cnt<<"\n";
    return 0;
}
