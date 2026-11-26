#include "bits/stdc++.h"
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    int ans=0;
    while(N--){
        string s;cin>>s;
        ans+=s[0]=='C';
    }
    cout<<ans<<"\n";
    return 0;
}
