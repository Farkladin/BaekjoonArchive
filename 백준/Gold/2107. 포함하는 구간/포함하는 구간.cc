#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
pii arr[25003];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    for(int i=1;i<=N;i++)cin>>arr[i].fi>>arr[i].se;
    sort(arr+1,arr+1+N);
    int ans=0;
    for(int i=1;i<=N;i++){
        int cur=0;
        for(int j=i+1;j<=N;j++){
            cur+=arr[i].fi<arr[j].fi&&arr[j].se<arr[i].se;
        }
        ans=max(ans,cur);
    }
    cout<<ans<<"\n";
    return 0;
}
