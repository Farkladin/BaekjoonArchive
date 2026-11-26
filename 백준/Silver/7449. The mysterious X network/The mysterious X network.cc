#include "bits/stdc++.h"
using namespace std;
vector<vector<int> >G;
int vis[100003];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;
    while(cin>>N){
        G.clear();
        G.resize(N+2);
        fill(vis,vis+N+2,0);
        while(N--){
            int c,n;cin>>c>>n;
            for(int i=1;i<=n;i++){
                int x;cin>>x;
                G[c].push_back(x);
                G[x].push_back(c);
            }
        }
        int src,sink;cin>>src>>sink;
        queue<int>q;q.push(src);
        vis[src]=1;
        while(!q.empty()){
            int u=q.front();q.pop();
            for(int v:G[u]){
                if(!vis[v]){
                    vis[v]=vis[u]+1;
                    q.push(v);
                }
            }
        }
        cout<<src<<" "<<sink<<" "<<vis[sink]-2<<"\n";
    }
    return 0;
}
