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

bool arr[200003];
void dfs(int x){
    for(int y:G[x]){
        if(arr[y])continue;
        arr[y]=true;
        dfs(y);
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,M;cin>>N>>M;
    G.resize(N+2);GT.resize(N+2);
    for(int i=0;i<M;i++){
        int v,w;cin>>v>>w;
        G[v].push_back(w);
        GT[w].push_back(v);
    }
    vis.resize(N+2);
    for(int x=1;x<=N;x++){
        if(vis[x])continue;
        vis[x]=true;
        DFS(x,false);
    }
    fill(vis.begin(),vis.end(),false);
    bool flag=false;
    while(!stk.empty()){
        int x=stk.top();stk.pop();
        if(vis[x])continue;
        vis[x]=true;
        SCC.push_back({x});
        DFS(x,true);
        if(!arr[x]&&flag){
            cout<<"0\n";
            return 0;
        }
        arr[x]=true;
        flag=true;
        dfs(x);
    }
    
    fill(vis.begin(),vis.end(),false);
    queue<int>q;q.push(SCC.back().back());
    int cnt=1;vis[q.front()]=true;
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int v:GT[u]){
            if(!vis[v]){
                vis[v]=true;
                q.push(v);
                cnt++;
            }
        }
    }
    if(cnt<N){
        cout<<"0\n";
        return 0;
    }
    cout<<SCC.front().size()<<"\n";
    sort(SCC.front().begin(),SCC.front().end());
    for(auto x:SCC.front())cout<<x<<" ";
    cout<<"\n";
    return 0;
}
