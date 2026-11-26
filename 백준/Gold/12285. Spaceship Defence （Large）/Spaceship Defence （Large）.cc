#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
void solve(){
    int N;cin>>N;
    vector<vector<pair<int,int> > >G(N+2);
    vector<string>color(N+2);
    map<string,int>mp;
    
    for(int i=1;i<=N;i++){
        cin>>color[i];
        if(!mp[color[i]])mp[color[i]]=i;
    }
    int M;cin>>M;
    while(M--){
        int a,b,t;cin>>a>>b>>t;
        a=mp[color[a]];
        b=mp[color[b]];
        G[a].push_back({b,t});
    }
    
    int S;cin>>S;
    while(S--){
        int p,q;cin>>p>>q;
        p=mp[color[p]];
        q=mp[color[q]];
        priority_queue<pair<int,int> >pq;pq.push({0,p});
        vector<int>dist(N+3,1<<30);
        dist[p]=0;
        while(!pq.empty()){
            auto [c,u]=pq.top();pq.pop();
            if(dist[u]<-c)continue;
            for(auto [v,w]:G[u]){
                if(dist[v]>w-c){
                    dist[v]=w-c;
                    pq.push({c-w,v});
                }
            }
        }
        cout<<(dist[q]==(1<<30)?-1:dist[q])<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int T;cin>>T;
    for(int tc=1;tc<=T;tc++){
        cout<<"Case #"<<tc<<":\n";
        solve();
    }
    return 0;
}
