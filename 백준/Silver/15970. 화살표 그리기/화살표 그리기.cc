#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    ll ans=0;
    vector<pair<ll,int> >arr(N+3);
    for(int i=1;i<=N;i++){
        cin>>arr[i].fi>>arr[i].se;
    }
    for(int i=1;i<=N;i++){
        ll cur=1e9;
        for(int j=1;j<=N;j++){
            if(i!=j&&arr[i].se==arr[j].se)cur=min(cur,abs(arr[i].fi-arr[j].fi));
        }
        ans+=cur;
    }
    cout<<ans<<"\n";
    return 0;
}
