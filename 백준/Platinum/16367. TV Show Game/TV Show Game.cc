#include "bits/stdc++.h"
using namespace std;

vector<vector<int> >G,GT,SCC;
vector<bool>vis;
stack<int>stk;
vector<int>cn;
int N,M;

void DFS(int x,const bool T){
    vector<int>&g=T?GT[x]:G[x];
    for(int y:g){
        if(vis[y])continue;
        vis[y]=true;
        if(T){
            SCC.back().push_back(y);
            cn[y]=(int)SCC.size();
        }
        DFS(y,T);
    }
    if(!T)stk.push(x);
}

void clearAll(){
    G.clear();
    GT.clear();
    SCC.clear();
    cn.clear();
    vis.clear();
    while(!stk.empty())stk.pop();
}

void resizeAll(){
    G.resize(2*N+2);
    GT.resize(2*N+2);
    SCC.resize(2*N+2);
    cn.resize(2*N+2);
    vis.resize(2*N+2);
}

inline int NOT(const int &x){
    return x<=N?x+N:x-N;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin>>N>>M;
    resizeAll();
    
    while(M--){
        int k1,k2,k3;char c1,c2,c3;cin>>k1>>c1>>k2>>c2>>k3>>c3;
        if(c1=='B')k1=NOT(k1);
        if(c2=='B')k2=NOT(k2);
        if(c3=='B')k3=NOT(k3);
        
        G[NOT(k1)].push_back(k2);
        GT[k2].push_back(NOT(k1));
        G[NOT(k2)].push_back(k1);
        GT[k1].push_back(NOT(k2));
        
        G[NOT(k2)].push_back(k3);
        GT[k3].push_back(NOT(k2));
        G[NOT(k3)].push_back(k2);
        GT[k2].push_back(NOT(k3));
        
        G[NOT(k3)].push_back(k1);
        GT[k1].push_back(NOT(k3));
        G[NOT(k1)].push_back(k3);
        GT[k3].push_back(NOT(k1));
    }
    
    fill(vis.begin(),vis.end(),false);
    for(int x=1;x<=2*N;x++){
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
        cn[x]=(int)SCC.size();
        DFS(x,true);
    }
    
    bool ans=true;
    for(int i=1;i<=N;i++)ans&=cn[i]!=cn[NOT(i)];
    if(!ans){
        cout<<"-1\n";
        return 0;
    }
    for(int i=1;i<=N;i++)cout<<(cn[i]>cn[NOT(i)]?'R':'B');
    cout<<"\n";
    return 0;
}
