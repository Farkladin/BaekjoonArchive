#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    string s;cin>>s;
    s.push_back('!');
    int cur=0,ans=0;
    for(auto c:s){
        if(c!='0'){
            ans+=cur;
            cur=0;
        }
        cur=cur*10+c-'0';
    }
    cout<<ans<<"\n";
    return 0;
}
