#include "bits/stdc++.h"
using namespace std;
using ll=long long;
vector<ll>P;
int8_t E[1'000'003];

ll phi(ll n){
    ll ret=n;
    for(ll p:P){
        if(p*p > n)break;
        if(n%p==0){
            ret -= ret/p;
            while(n%p == 0){
                n/=p;
            }
        }
    }
    
    if(n>1) ret-=ret/n;
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    for(int i=2; i<=1'000'000; ++i){
        if(E[i])continue;
        P.push_back(i);
        for(int j=i+i; j<=1'000'000; j+=i){
            E[j]=1;
        }
    }
    
    ll n; cin>>n;
    
    vector<ll>X; X.reserve(100000);
    for(ll y=1; y*y<=n; ++y){
        if(n%y==0)X.push_back(n/y);
    }
    
    for(ll x:X){
        if(x*phi(x)==n){
            cout<<x<<"\n";
            return 0;
        }
    }
    
    cout<<"-1\n";
    return 0;
}
