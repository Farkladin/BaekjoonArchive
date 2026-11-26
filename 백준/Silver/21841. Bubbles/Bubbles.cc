#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll P,W,N;cin>>P>>W>>N;
    ll x=0,y=0,ans=0;
    while(N--){
        char c;int garb;cin>>c>>garb;
        if(c=='P'){
            x++;
            ans+=P;
        }else{
            y++;
            ans+=W;
        }
    }
    cout<<ans-x*y<<"\n";
    return 0;
}
