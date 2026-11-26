#include "bits/stdc++.h"
using namespace std;

vector<vector<int> >G,GT,SCC;
vector<bool>vis;
stack<int>stk;
void DFS(int x,const bool T){
    auto &g=T?GT[x]:G[x];
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
    int tc;cin>>tc;
    while(tc--){
        int N,M;cin>>N>>M;
        G.resize(N+2);
        GT.resize(N+2);
        vis.resize(N+2);
        
        while(M--){
            int x,y;cin>>x>>y;
            x++;y++;
            G[x].push_back(y);
            GT[y].push_back(x);
        }
        
        fill(vis.begin(),vis.end(),false);
        for(int x=1;x<=N;x++){
            if(vis[x])continue;
            vis[x]=true;
            DFS(x,false);
        }
        
        fill(vis.begin(),vis.end(),false);
        while(!stk.empty()){
            int x=stk.top();stk.pop();
            if(vis[x])continue;
            vis[x]=true;
            SCC.push_back({x});
            DFS(x,true);
        }
        
        fill(vis.begin(),vis.end(),false);
        int cnt=1;
        queue<int>q;q.push(SCC.front().front());
        vis[SCC.front().front()]=true;
        while(!q.empty()){
            int u=q.front();q.pop();
            for(int v:G[u]){
                if(vis[v])continue;
                vis[v]=true;
                q.push(v);
                cnt++;
            }
        }
        if(cnt<N)cout<<"Confused\n";
        else{
            sort(SCC.front().begin(),SCC.front().end());
            for(auto &x:SCC.front())cout<<x-1<<"\n";
        }
        cout<<"\n";
        
        vis.clear();
        G.clear();
        GT.clear();
        vis.clear();
        SCC.clear();
    }
    
    return 0;
}
