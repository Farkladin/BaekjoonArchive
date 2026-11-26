#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int T;cin>>T;
    cout<<fixed;
    cout.precision(10);
    for(int tc=1;tc<=T;tc++){
        cout<<"Case #"<<tc<<": ";
        map<string,int>mp;
        int idx=0;
        int M;cin>>M;
        vector<vector<int> >G(M*2+3);
        while(M--){
            string a,b;cin>>a>>b;
            if(!mp[a])mp[a]=++idx;
            if(!mp[b])mp[b]=++idx;
            G[mp[a]].push_back(mp[b]);
            G[mp[b]].push_back(mp[a]);
        }
        
        vector<int>grp(idx+3);
        for(int i=1;i<=idx;i++){
            if(grp[i])continue;
            queue<int>q;q.push(i);
            grp[i]=1;
            while(!q.empty()){
                int u=q.front();q.pop();
                for(int v:G[u]){
                    if(grp[v]==grp[u]){
                        cout<<"No\n";
                        goto skip;
                    }
                    if(!grp[v]){
                        grp[v]=grp[u]^2;
                        q.push(v);
                    }
                }
            }
        }
        cout<<"Yes\n";
        skip:
    }
    return 0;
}
