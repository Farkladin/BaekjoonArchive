#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;cin>>n;
    while(n--){
        int p;cin>>p;
        pair<int,string>ans;
        while(p--){
            pair<int,string>p;
            cin>>p.fi>>p.se;
            ans=max(ans,p);
        }
        cout<<ans.second<<"\n";
    }
    return 0;
}
