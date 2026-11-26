#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll x,y;cin>>x>>y;
    ll r;cin>>r;
    cout<<x-r<<" "<<y-r<<"\n"<<x-r<<" "<<y+r<<"\n"<<x+r<<" "<<y+r<<"\n"<<x+r<<" "<<y-r<<"\n";
    return 0;
}
