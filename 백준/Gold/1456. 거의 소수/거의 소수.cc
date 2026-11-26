#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
bool mask[10000003];
constexpr int MAXINT=1e7;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll A,B;cin>>A>>B;
    int cnt=0;
    for(ll i=2;i<=MAXINT;i++){
        if(mask[i])continue;
        for(ll j=i+i;j<=MAXINT;j+=i)mask[j]=true;
        __int128_t N=i*i;
        while(N<=B){
            if(A<=N)cnt++;
            N*=i;
        }
    }
    cout<<cnt<<"\n";
    return 0;
}
