#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
using ull=unsigned long long;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll N;cin>>N;
    ll lcm=1;
    ll tmp=N;
    while(tmp){
        ll k=(tmp%10);
        if(k!=0)lcm=lcm*k/gcd(lcm,k);
        tmp/=10;
    }
    
    for(ll k=1;k<=1e4;k*=10){
        for(ll i=0;i<k;i++){
            if((N*k+i)%lcm==0){
                cout<<N*k+i<<"\n";
                return 0;
            }
        }
    }
    
    // fail
    return 1;
}
