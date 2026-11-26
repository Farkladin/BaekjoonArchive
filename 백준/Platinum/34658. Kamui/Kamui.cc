#include "bits/stdc++.h"
using namespace std;
using ll = long long;

ll S[500003];

constexpr ll mod=998244353;
inline ll c2(ll n){
    return ((n*(n-1))>>1)%mod;
}

int arr[500003];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int N,Q;cin>>N>>Q;
    for(int i=1;i<=N;++i){
        cin>>arr[i];
        ++S[arr[i]];
    }
    for(int i=1;i<=N;++i){
        S[i]+=S[i-1];
    }
    ll sum=0;
    for(int i=1;i<=N;++i){
        sum=(sum + (i-1)*c2(S[N]-S[i-1])) %mod;
    }
    
    while(Q--){
        int v,x;cin>>v>>x;
        int &i=arr[v];
        if(x==1){
            sum=(sum+i*(S[N]-S[i]))%mod;
            --S[i++];
        }else{
            sum=(sum+mod-(i-1)*(S[N]-S[i-1]-1)%mod) %mod;
            ++S[--i];
        }
        cout<<sum<<"\n";
    }
    
    return 0;
}
