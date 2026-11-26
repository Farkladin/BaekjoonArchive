#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int T;cin>>T;
    for(int tc=1;tc<=T;tc++){
        int A,B;cin>>A>>B;
        cout<<format("Case #{:d}: {:d} + {:d} = {:d}",tc,A,B,A+B)<<"\n";
    }
    return 0;
}
