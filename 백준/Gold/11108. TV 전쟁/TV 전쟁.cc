#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<vector<ll> >arr(n+3,vector<ll>(5));
        for(int i=1;i<=n;i++){
            cin>>arr[i][1]>>arr[i][0]>>arr[i][2];
            arr[i][0]+=arr[i][1];
        }
        sort(arr.begin()+1,arr.begin()+1+n);
        set<pair<ll,ll> >sp={{0,0}};
        for(int i=1;i<=n;i++){
            auto it=sp.upper_bound(pair<ll,ll>(arr[i][1],1e18));it--;
            pair<ll,ll>cur={arr[i][0],arr[i][2]+it->second};
            it=sp.upper_bound(pair<ll,ll>(arr[i][0],1e18));it--;
            if(it->second<cur.second)sp.insert(cur);
        }
        ll ans=0;
        for(auto p:sp)ans=max(ans,p.second);
        cout<<ans<<"\n";
    }
    return 0;
}
