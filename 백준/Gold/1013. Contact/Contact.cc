#include "bits/stdc++.h"
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int T;cin>>T;
    while(T--){
        string s;cin>>s;
        regex r("(100+1+|01)+");
        cout<<(regex_match(s,r)?"YES":"NO")<<"\n";
    }
    return 0;
}
