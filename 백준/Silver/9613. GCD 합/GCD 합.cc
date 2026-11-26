#include "bits/stdc++.h"
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<ll>arr(n+2);
        ll ans=0;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            for(int j=1;j<i;j++){
                ans+=gcd(arr[i],arr[j]);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
