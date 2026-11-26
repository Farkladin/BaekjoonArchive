#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
pair<ll,ll>arr[303];
ll dist(pair<ll,ll>a,pair<ll,ll>b){
    return (a.fi-b.fi)*(a.fi-b.fi)+(a.se-b.se)*(a.se-b.se);
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>arr[i].fi>>arr[i].se;
    ll ans=1e18;
    for(int i=1;i<=n;i++){
        ll cur=0;
        vector<bool>vis(n+2);
        vis[i]=true;
        int x=i;
        for(int j=1;j<n;j++){
            int idx=0;
            ll mn=1e18;
            for(int k=1;k<=n;k++){
                if(!vis[k]&&dist(arr[x],arr[k])<mn){
                    mn=dist(arr[x],arr[k]);
                    idx=k;
                }
            }
            vis[idx]=true;
            x=idx;
            cur+=mn;
        }
        ans=min(cur,ans);
    }
    cout<<ans<<"\n";
    return 0;
}
