#include "bits/stdc++.h"
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N,K; cin>>N>>K;
    int ans=1;
    for(int i=2;i<=N;++i){
        int x=(K-1)%i+1;
        ans=(x+ans-1)%i+1;
    }
    cout<<ans<<"\n";
    return 0;
}
