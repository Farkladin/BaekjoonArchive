#include "bits/stdc++.h"
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    map<string,string>mp;
    int N,M;cin>>N>>M;
    while(N--){
        string s,t;cin>>s>>t;
        mp[s]=t;
    }
    
    while(M--){
        string s;cin>>s;
        cout<<mp[s]<<"\n";
    }
    return 0;
}
