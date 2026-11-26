#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    int ans=2;
    while(N--){
        ans=ans*2-1;
    }
    cout<<ans*ans<<"\n";
    return 0;
}
