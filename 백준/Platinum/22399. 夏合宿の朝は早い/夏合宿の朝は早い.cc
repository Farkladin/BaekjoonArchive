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

double p[100003];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cout<<fixed<<setprecision(9);
    
    while(1){
        int N;cin>>N;
        if(N==0)break;
        G.resize(N+2);
        GT.resize(N+2);
        vis.resize(N+2);
        
        for(int i=1;i<=N;++i){
            cin>>p[i];
            int m;cin>>m;
            while(m--){
                int a;cin>>a;
                G[i].push_back(a);
                GT[a].push_back(i);
            }
        }
        
        fill(vis.begin(),vis.end(),0);
        for(int x=1;x<=N;x++){
            if(vis[x])continue;
            vis[x]=1;
            DFS(x,false);
        }
        
        fill(vis.begin(),vis.end(),0);
        waked.resize(N+3);
        
        while(!stk.empty()){
            int x=stk.top();stk.pop();
            if(waked[x])continue;
            vis[x]=1;
            SCC.push_back({x});
            DFS(x,true);
            dfs(x);
        }
        
        double ans=1;
        for(auto &scc:SCC){
            double cur=1;
            for(int x:scc)cur*=p[x];
            ans*=1-cur;
        }
        cout<<ans<<"\n";
        
        SCC.clear();
        waked.clear();
        vis.clear();
        G.clear();
        GT.clear();
    }
    return 0;
}
