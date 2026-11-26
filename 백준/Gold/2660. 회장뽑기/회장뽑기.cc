#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
vector<vector<int> >G;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    G.resize(N+3);
    while(1){
        int a,b;cin>>a>>b;
        if(a==-1&&b==-1)break;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int mn=1e9;
    vector<int>ans;
    for(int i=1;i<=N;i++){
        queue<int>q;q.push(i);
        vector<int>vis(N+3,-1);
        vis[i]=0;
        int cur=0;
        while(!q.empty()){
            int u=q.front();q.pop();
            for(int v:G[u]){
                if(vis[v]==-1){
                    vis[v]=vis[u]+1;
                    cur=max(cur,vis[v]);
                    q.push(v);
                }
            }
        }
        if(mn>cur){
            mn=cur;
            ans.clear();
        }
        if(mn==cur){
            ans.push_back(i);
        }
    }
    cout<<mn<<" "<<ans.size()<<"\n";
    for(auto a:ans)cout<<a<<" ";
    cout<<"\n";
    return 0;
}
