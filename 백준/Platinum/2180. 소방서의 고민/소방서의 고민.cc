#include "bits/stdc++.h"
using namespace std;
using ll=long long;

struct Type{
    ll a,b;
}arr[200003];

inline bool cmp(const Type &lhs, const Type &rhs){
    return lhs.b*rhs.a < lhs.a*rhs.b || (lhs.b*rhs.a == lhs.a*rhs.b && lhs.b<rhs.b);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin>>n;
    for(int i=1; i<=n; ++i) cin>>arr[i].a>>arr[i].b;
    sort(arr+1,arr+1+n,cmp);
    
    ll ans=0;
    for(int i=1; i<=n; ++i){
        ans = (ans + ans*arr[i].a + arr[i].b)%40000;
    }
    cout<<ans<<"\n";
    
    return 0;
}
