#include "bits/stdc++.h"
using namespace std;
vector<vector<int> >G,GT,SCC;
vector<bool>vis;
stack<int>stk;

void DFS(int x,const bool T){
    vector<int>&g=T?GT[x]:G[x];
    for(int y:g){
        if(vis[y])continue;
        vis[y]=true;
        if(T)SCC.back().push_back(y);
        DFS(y,T);
    }
    if(!T)stk.push(x);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    G.resize(N+2);
    GT.resize(N+2);
    vis.resize(N+2);
    vector<int>cost(N+2);
    for(int i=1;i<=N;i++)cin>>cost[i];
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            char c;cin>>c;
            if(c=='1'){
                G[i].emplace_back(j);
                GT[j].emplace_back(i);
            }
        }
    }
    for(int i=1;i<=N;i++){
        if(vis[i])continue;
        vis[i]=true;
        DFS(i,false);
    }
    fill(vis.begin(),vis.end(),false);
    while(!stk.empty()){
        int x=stk.top();stk.pop();
        if(vis[x])continue;
        vis[x]=true;
        SCC.push_back({x});
        DFS(x,true);
    }
    
    int ans=0;
    for(auto &scc:SCC){
        int mn=1e9;
        for(auto &x:scc)mn=min(mn,cost[x]);
        ans+=mn;
    }
    
    cout<<ans<<"\n";
    return 0;
}
