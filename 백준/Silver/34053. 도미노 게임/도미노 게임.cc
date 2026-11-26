#include "bits/stdc++.h"
using namespace std;
using ll=long long;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    int N,M;cin>>N>>M;
    ll sum=0,mn=1e18;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            ll a;cin>>a;
            sum+=a;
            mn=min(mn,a);
        }
    }
    cout<<sum-mn<<"\n";
    return 0;
}
