#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    int ans=0;
    while(N--){
        char c;cin>>c;
        ans+=c-'0';
    }
    cout<<ans<<"\n";
    return 0;
}
