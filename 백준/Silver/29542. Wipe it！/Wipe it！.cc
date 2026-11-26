#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    vector<int>mp(256);
    string s;cin>>s;
    string cur;
    for(auto c:s){
        if(mp[c])continue;
        cur.push_back(c);
        mp[c]=1;
    }
    cout<<cur<<"\n";
    return 0;
}
