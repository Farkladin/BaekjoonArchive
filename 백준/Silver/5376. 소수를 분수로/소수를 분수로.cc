#include "bits/stdc++.h"
using namespace std;
using ll=long long;
int main(){
    int T;cin>>T;
    while(T--){
        string s;cin>>s;
        ll n=0,m=1,t=1;
        int i=2;
        for(;i<(int)s.size();i++){
            if(s[i]=='(')break;
            n=n*10+s[i]-'0';
            m*=10;
            t*=10;
        }
        if(i==(int)s.size()){
            ll tmp=gcd(n,m);
            cout<<n/tmp<<"/"<<m/tmp<<"\n";
            continue;
        }
        i++;
        ll x=0,y=1;
        for(;i<(int)s.size()-1;i++){
            x=x*10+s[i]-'0';
            y*=10;
            t*=10;
        }
        ll no=n*y+x-n,de=t-m;
        ll tmp=gcd(no,de);
        cout<<no/tmp<<"/"<<de/tmp<<"\n";
    }
    return 0;
}
