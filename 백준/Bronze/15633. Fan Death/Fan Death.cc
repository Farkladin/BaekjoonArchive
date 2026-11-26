#include "bits/stdc++.h"
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;cin>>n;
    ll ans=0;
    for(int i=1;i<=n;i++){
        if(n%i==0)ans+=i;
    }
    cout<<ans*5-24<<"\n";
    return 0;
}
