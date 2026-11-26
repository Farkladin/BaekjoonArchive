#include "bits/stdc++.h"
#include <format>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;cin>>n;
    map<string,int>mp;
    vector<vector<string> >arr(n);
    for(auto &vs:arr){
        int k;cin>>k;
        vs.resize(k);
        for(auto &s:vs){
            cin>>s;
            mp[s]=1;
        }
    }
    for(auto &vs:arr){
        for(auto &s:vs){
            if(mp[s]){
                mp[s]=0;
                cout<<s<<" ";
                break;
            }
        }
    }
    cout<<"\n";
    return 0;
}
