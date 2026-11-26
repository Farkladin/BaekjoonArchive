#include "bits/stdc++.h"
using namespace std;

vector<vector<int> >G,GT,SCC;
vector<int8_t>vis,waked;
stack<int>stk;
void DFS(int x,const bool T){
    const vector<int> &g = T?GT[x]:G[x];
    for(int y:g){
        if(vis[y])continue;
        vis[y]=true;
        if(T)SCC.back().push_back(y);
        DFS(y,T);
    }
    if(!T)stk.push(x);
}

void dfs(int x){
    for(int y:G[x]){
        if(waked[y])continue;
        waked[y]=true;
        dfs(y);
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cout<<fixed<<setprecision(9);
    while(1){
        int c,b; cin>>c>>b;
        G.resize(c+2);
        GT.resize(c+2);
        vis.resize(c+2);
        
        for(int i=1;i<=b;++i){
            int l,m;cin>>l>>m;
            while(m--){
                int x;cin>>x;
                G[l].push_back(x);
                GT[x].push_back(l);
            }
        }
        
        fill(vis.begin(),vis.end(),0);
        for(int x=1;x<=c;x++){
            if(vis[x])continue;
            vis[x]=1;
            DFS(x,false);
        }
        
        fill(vis.begin(),vis.end(),0);
        waked.resize(c+3);
        
        while(!stk.empty()){
            int x=stk.top();stk.pop();
            if(waked[x])continue;
            vis[x]=1;
            SCC.push_back({x});
            DFS(x,true);
            dfs(x);
        }
        
        if(SCC.size()==1){
            cout<<SCC.back().size()<<"\n";
        }else cout<<"0\n";
        
        SCC.clear();
        waked.clear();
        vis.clear();
        G.clear();
        GT.clear();
        
        break;
    }
    return 0;
}
