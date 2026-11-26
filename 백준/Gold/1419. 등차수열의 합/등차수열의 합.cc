#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // k*(2*x+(k-1)*d)/2
    // k*x + k*(k-1)/2*d
    // l <= a*x + b*d <= r
    ll l,r,k;cin>>l>>r>>k;
    switch(k){
        case 1:
            cout<<r-l+1<<"\n";
            break;
        case 2:
            // 2*x + d
            if(r<3)cout<<"0\n";
            else cout<<r-max(l-1,2LL)<<"\n";
            break;
        case 3:
            // 3*x + 3*d
            if(r<6)cout<<"0\n";
            else cout<<r/3-max(5LL,l-1)/3<<"\n";
            break;
        case 4:{
            // 4*x + 6*d
            // (2*x + 3*d) * 2
            ll ans=0;
            if(l<=10&&10<=r)ans++;
            l=max(l,14LL);
            if(l&1)l++;
            if(r&1)r--;
            if(l<=r)ans+=((r-l)>>1)+1;
            cout<<ans<<"\n";
            break;
        }
        case 5:
            // 5*x + 10*d
            if(r<15)cout<<"0\n";
            else cout<<r/5-max(14LL,l-1)/5<<"\n";
            break;
        default:
            break;
    }
    return 0;
}
