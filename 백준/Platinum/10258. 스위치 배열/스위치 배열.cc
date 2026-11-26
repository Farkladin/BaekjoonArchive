#include "bits/stdc++.h"
using namespace std;
using u64 = uint64_t;

void solve(){
    string B; cin>>B;
    u64 b=0;
    for(size_t i=0; i<B.size(); ++i){
        if(B[i]=='1')b|=(1ull<<(B.size()-i-1));
    }
    
    u64 k=b>>1;
    while(k){
        b=b^k;
        k>>=1;
    }
    
    cout<<b<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;cin>>T;
    while(T--)solve();
    return 0;
}
