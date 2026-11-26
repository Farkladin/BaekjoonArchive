#include "bits/stdc++.h"
using namespace std;
using ll=long long;
constexpr ll r=31,M=1234567891;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int L;cin>>L;
    string s;cin>>s;
    ll ans=0;
    reverse(s.begin(),s.end());
    for(auto c:s){
        ans=(ans*r+(c-'a'+1))%M;
    }
    cout<<ans<<"\n";
    return 0;
}
