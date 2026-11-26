#include "bits/stdc++.h"
using namespace std;
using ll=long long;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int H,W;cin>>H>>W;
    vector<int>pmx(W+3),arr(W+3);
    for(int i=1;i<=W;i++){
        cin>>arr[i];
        pmx[i]=max(pmx[i-1],arr[i]);
    }
    int ans=0,mx=0;
    for(int i=W;i>0;i--){
        mx=max(arr[i],mx);
        ans+=min(pmx[i],mx)-arr[i];
    }
    cout<<ans<<"\n";
    return 0;
}
