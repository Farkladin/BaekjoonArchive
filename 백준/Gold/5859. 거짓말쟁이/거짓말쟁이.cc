#include "bits/stdc++.h"
using namespace std;
using pii=pair<int,int>;
vector<int>G[2003];

bitset<2003>vis;
int NOT(int x){
    if(x>1000)return x-1000;
    else return x+1000;
}
bool dfs(int x){
    bool ret=true;
    for(auto y:G[x]){
        if(vis[NOT(y)])return false;
        if(!vis[y]){
            vis.set(y);
            ret&=dfs(y);
        }
    }
    return ret;
}

array<int,3> edges[10003];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,M;cin>>N>>M;
    for(int i=1;i<=M;i++){
        int x,y;string s;
        cin>>x>>y>>s;
        edges[i]={x,y,s=="T"};
    }
    
    for(int i=1;i<=M;i++){
        fill(G,G+2001,vector<int>());
        for(int j=1;j<=i;j++){
            auto [x,y,w]=edges[j];
            if(w){
                G[x].emplace_back(y);
                G[x+1000].emplace_back(y+1000);
                G[y].emplace_back(x);
                G[y+1000].emplace_back(x+1000);
            }
            else{
                G[x].emplace_back(y+1000);
                G[y+1000].emplace_back(x);
                G[x+1000].emplace_back(y);
                G[y].emplace_back(x+1000);
            }
        }
        
        vis.reset();
        for(int x=1;x<=N;x++){
            if(vis[x]==0 && vis[NOT(x)]==0){
                if(!dfs(x)){
                    cout<<i-1<<"\n";
                    return 0;
                }
            }
        }
    }
    cout<<M<<"\n";
    return 0;
}
