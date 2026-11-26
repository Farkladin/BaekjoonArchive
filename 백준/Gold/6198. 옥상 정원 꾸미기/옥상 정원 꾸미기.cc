#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int arr[80003];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    for(int i=1;i<=N;i++)cin>>arr[i];
    stack<pair<int,int> >stk;
    ll ans=0;
    for(int i=N;i>0;i--){
        int cur=1;
        while(!stk.empty()&&stk.top().fi<arr[i]){
            cur+=stk.top().se;
            stk.pop();
        }
        stk.push({arr[i],cur});
        ans+=cur-1;
    }
    cout<<ans<<"\n";
    return 0;
}
