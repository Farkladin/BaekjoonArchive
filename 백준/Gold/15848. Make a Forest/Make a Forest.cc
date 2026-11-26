#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
map<int,int>mp;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,M;cin>>N>>M;
    int idx=0;
    vector<array<int,3> >sv(N+3);
    vector<set<pii> >G(N*2+3);
    for(int i=1;i<=N;i++){
        int u,v,w;cin>>u>>v>>w;
        if(!mp[u])mp[u]=++idx;
        if(!mp[v])mp[v]=++idx;
        sv[i]={w,mp[u],mp[v]};
    }
    vector<bool>used(N+3);
    int ans=0;
    sort(sv.begin()+1,sv.begin()+1+N);
    for(int i=1;i<=N;i++){
        G[sv[i][1]].insert({sv[i][0],i});
    }
    for(int i=1;i<=N;i++){
        if(used[i])continue;
        ans++;
        queue<pii>q;q.push({sv[i][1],0});
        while(!q.empty()){
            auto u=q.front();q.pop();
            int cnt=0;
            vector<pii>era;
            for(auto p:G[u.fi]){
                if(cnt>=M)break;
                if(p.fi<=u.se||used[p.se])continue;
                cnt++;
                used[p.se]=true;
                era.push_back(p);
                q.push({sv[p.se][2],p.fi});
            }
            for(auto p:era)G[u.fi].erase(p);
        }
    }
    cout<<ans<<"\n";
    return 0;
}
