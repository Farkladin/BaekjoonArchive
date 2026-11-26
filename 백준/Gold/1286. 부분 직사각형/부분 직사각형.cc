#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
ll res[30];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,M;cin>>N>>M;
    for(ll i=1;i<=N;i++){
        for(ll j=1;j<=M;j++){
            char c;cin>>c;
            ll tmp=j*(2*M-j+1)+(j+M)*(M-j+1);
            res[c-'A']+=i*(2*N-i+1)*tmp+(N+i)*(N-i+1)*tmp;
        }
    }
    for(int i=0;i<26;i++)cout<<res[i]<<"\n";
    return 0;
}
