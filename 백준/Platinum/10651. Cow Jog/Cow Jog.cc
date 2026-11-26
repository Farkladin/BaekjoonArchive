#include "bits/stdc++.h"
using namespace std;
using ll=long long;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N; ll T; cin>>N>>T;
    
    vector<ll>vec(N);
    for(int i=0; i<N; ++i){
        ll s0,v; cin>>s0>>v;
        vec[i]=-s0-v*T;
    }
    
    vector<ll>lis;
    for(auto x:vec){
        if(lis.empty() || lis.back()<=x){
            lis.push_back(x);
        }else{
            auto it = upper_bound(lis.begin(),lis.end(),x);
            *it = x;
        }
    }
    
    cout<<lis.size()<<"\n";
    return 0;
}
