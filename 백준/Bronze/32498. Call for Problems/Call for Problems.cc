#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;cin>>n;
    int ans=0;
    while(n--){
        int d;cin>>d;
        ans+=d&1;
    }
    cout<<ans<<"\n";
    return 0;
}
