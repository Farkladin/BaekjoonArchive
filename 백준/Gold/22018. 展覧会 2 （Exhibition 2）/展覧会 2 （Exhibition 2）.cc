#include "bits/stdc++.h"
using namespace std;
using ll=long long;
#define fi first
#define se second
using pii=pair<ll,ll>;
pii arr[100003];
ll N,M,D;
bool g(ll w){
    ll cur=-1e15;
    for(int i=1,j=0;i<=M;i++){
        while(j<N&&arr[j+1].fi<cur+D)j++;
        while(j<N&&arr[j+1].fi>=cur+D){
            j++;
            if(arr[j].se>=w){
                cur=arr[j].fi;
                goto nxt;
            }
        }
        return false;
        nxt:
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin>>N>>M>>D;
    for(int i=1;i<=N;i++)cin>>arr[i].fi>>arr[i].se;
    sort(arr+1,arr+1+N);
    ll le=0,ri=2e9,ans=-1;
    while(le<ri+1){
        ll mid=(le+ri)>>1;
        if(g(mid)){
            ans=max(ans,mid);
            le=mid+1;
        }else{
            ri=mid-1;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
