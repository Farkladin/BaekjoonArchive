#include "bits/stdc++.h"
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    string s;cin>>s;
    ll ans=0;
    for(char c:s){
        ans=ans*26+c-'A'+1;
    }
    cout<<ans<<"\n";
    return 0;
}
