#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
ll arr[53];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    multiset<ll>box;
    int N;cin>>N;
    for(int i=1;i<=N;i++)cin>>arr[i];
    sort(arr+1,arr+1+N);
    ll mx=0;
    int M;cin>>M;
    for(int i=1;i<=M;i++){
        ll x;cin>>x;
        mx=max(mx,x);
        box.insert(x);
    }
    if(mx>arr[N]){
        cout<<"-1\n";
        return 0;
    }
    ll ans=0;
    while(!box.empty()){
        ans++;
        for(int i=1;i<=N;i++){
            ll tmp=arr[i];
            auto it=box.upper_bound(tmp);
            if(it==box.begin())continue;
            it--;
            tmp-=*it;
            box.erase(it);
        }
    }
    cout<<ans<<"\n";
    return 0;
}
