#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,K;cin>>N>>K;
    int ans=0;
    if(K==0){
        cout<<"-1\n";
        return 0;
    }
    while(__builtin_popcount(N)>K){
        N++;
        ans++;
    }
    cout<<ans<<"\n";
    return 0;
}
