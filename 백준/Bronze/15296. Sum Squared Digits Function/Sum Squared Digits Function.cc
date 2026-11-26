#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int P;cin>>P;
    while(P--){
        long long K,b,n;cin>>K>>b>>n;
        long long ans=0;
        while(n){
            long long cur=n%b;
            ans+=cur*cur;
            n/=b;
        }
        cout<<K<<" "<<ans<<"\n";
    }
    return 0;
}
