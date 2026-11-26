#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int vis[1000003];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll N;cin>>N;
    ll cur=1%N;
    int cnt=0;
    while(!vis[cur]){
        vis[cur]=++cnt;
        cur=(cur*10+1)%N;
    }
    cout<<(vis[0]?vis[0]:-1)<<"\n";
    return 0;
}
