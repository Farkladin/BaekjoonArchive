#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll X;cin>>X;
    int N;cin>>N;
    ll sum=0;
    while(N--){
        ll a,b;cin>>a>>b;
        sum+=a*b;
    }
    cout<<(sum==X?"Yes\n":"No\n");
    return 0;
}
