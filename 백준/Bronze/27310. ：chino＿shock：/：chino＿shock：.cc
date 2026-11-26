#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    string s;cin>>s;
    int ans=0;
    for(char c:s){
        ans++;
        if(c==':')ans++;
        if(c=='_')ans+=5;
    }
    cout<<ans<<"\n";
    return 0;
}
