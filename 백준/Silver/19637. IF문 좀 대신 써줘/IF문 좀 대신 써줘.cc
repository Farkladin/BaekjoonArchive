#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,M;cin>>N>>M;
    vector<pair<int,string> >vp;
    for(int i=0;i<N;i++){
        int x;string s;cin>>s>>x;
        if(vp.empty()||x>vp.back().fi)vp.push_back({x,s});
    }
    while(M--){
        int x;cin>>x;
        auto it=lower_bound(vp.begin(),vp.end(),pair<int,string>(x,"!"));
        cout<<it->second<<"\n";
    }
    return 0;
}
