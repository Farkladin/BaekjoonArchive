#include "bits/stdc++.h"
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    ll ans=1;
    for(int i=1;i<=N;i++){
        ans*=i;
        while(ans%10==0)ans/=10;
        ans%=2000000;
    }
    cout<<ans%10<<"\n";
    return 0;
}
