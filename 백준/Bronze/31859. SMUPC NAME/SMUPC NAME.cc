#include "bits/stdc++.h"
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;cin>>n;
    string s;cin>>s;
    vector<int>vis(256);
    string t;
    int cnt=0;
    for(auto c:s){
        if(vis[c])cnt++;
        else{
            t.push_back(c);
            vis[c]=1;
        }
    }
    t+=to_string(cnt+4);
    t=to_string(1906+n)+t;
    reverse(t.begin(),t.end());
    cout<<"smupc_"<<t<<"\n";
    return 0;
}
