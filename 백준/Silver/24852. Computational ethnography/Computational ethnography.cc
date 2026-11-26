#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll A,B;cin>>A>>B;
    int cnt=0;
    for(ll i=1;i<=1e6;i++){
        if(i*i>=A&&i*i<=B){
            string tmp=to_string(i*i);
            reverse(tmp.begin(),tmp.end());
            if(tmp[0]=='0')continue;
            ll x=stoll(tmp);
            ll a=sqrt(x)+1e-6;
            if(a*a==x){
                cnt++;
            }
        }
    }
    cout<<cnt<<"\n";
    return 0;
}
