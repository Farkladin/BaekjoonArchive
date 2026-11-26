#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
map<int,int>mp;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    vector<pair<int,int> >vp;
    for(int i=0;i<N;i++){
        int garb,st,ed;cin>>garb>>st>>ed;
        mp[st]++;
        mp[ed]--;
    }
    int cur=0,ans=0;
    for(auto p:mp){
        cur+=p.se;
        ans=max(ans,cur);
    }
    cout<<ans<<"\n";
    return 0;
}
