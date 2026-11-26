#include "bits/stdc++.h"
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int T;cin>>T;
    while(T--){
        int N;cin>>N;
        if(N==1){
            ll garb;cin>>garb;
            goto FAIL;
        }
        {
            ll a,b;cin>>a>>b;
            ll ans=b-a;
            for(int i=2;i<N;i++){
                ll x;cin>>x;
                ans=gcd(ans,x-b);
                b=x;
            }
            if(ans==0)goto FAIL;
            cout<<ans<<"\n";
        }
        continue;
        FAIL:
        cout<<"INFINITY\n";
    }
    return 0;
}
