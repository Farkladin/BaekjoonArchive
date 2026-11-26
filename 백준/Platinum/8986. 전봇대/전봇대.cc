#include "bits/stdc++.h"
using namespace std;
using ll=long long;

ll arr[100003];
int N;
ll f(ll d){
    ll ret=0, x=0;
    for(int i=1; i<N; ++i){
        x+=d;
        ret+=abs(arr[i]-x);
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>N;
    for(int i=0; i<N; ++i)cin>>arr[i];
    
    ll le=1,ri=1e9;
    while(ri-le>=3){
        ll m13=(le+le+ri)/3, m23=(le+ri+ri)/3;
        ll c1=f(m13), c2=f(m23);
        if(c2<c1)le=m13;
        else ri=m23;
    }
    
    ll mn=1e18;
    for(ll t=le; t<=ri; ++t){
        mn = min(mn, f(t));
    }
    
    cout<<mn<<"\n";
    
    return 0;
}
