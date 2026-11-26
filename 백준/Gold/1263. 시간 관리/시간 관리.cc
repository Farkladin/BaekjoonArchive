#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
pair<int,int>arr[1003];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    for(int i=1;i<=N;i++){
        cin>>arr[i].se>>arr[i].fi;
    }
    sort(arr+1,arr+1+N,greater<pair<int,int> >());
    int t=1e9;
    for(int i=1;i<=N;i++){
        t=min(t,arr[i].fi);
        t-=arr[i].se;
    }
    cout<<(t<0?-1:t)<<"\n";
    
    return 0;
}
