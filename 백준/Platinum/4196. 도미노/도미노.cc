#include "bits/stdc++.h"
using namespace std;

vector<vector<int> >G;
vector<bool>vis;
stack<int>stk;
void DFS(int x,const bool T){
    for(int y:G[x]){
        if(vis[y])continue;
        vis[y]=true;
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
        vis.resize(N+2);
        
        while(M--){
            int x,y;cin>>x>>y;
            G[x].push_back(y);
        }
        
        fill(vis.begin(),vis.end(),false);
        for(int x=1;x<=N;x++){
            if(vis[x])continue;
            vis[x]=true;
            DFS(x,false);
        }
        
        fill(vis.begin(),vis.end(),false);
        int cnt=0;
        while(!stk.empty()){
            int x=stk.top();stk.pop();
            if(vis[x])continue;
            vis[x]=true;
            DFS(x,true);
            cnt++;
        }
        cout<<cnt<<"\n";
        
        G.clear();
        vis.clear();
    }
    
    return 0;
}
