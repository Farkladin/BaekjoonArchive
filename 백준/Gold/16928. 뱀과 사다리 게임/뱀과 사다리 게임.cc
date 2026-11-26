#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int mp[103],vis[103];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,M;cin>>N>>M;
    for(int i=1;i<=100;i++)mp[i]=i;
    for(int i=1;i<=N+M;i++){
        int x,y;cin>>x>>y;
        mp[x]=y;
    }
    queue<int>q;q.push(1);
    vis[1]=1;
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=1;i<=6;i++){
            if(i+u<=100&&!vis[mp[i+u]]){
                vis[mp[i+u]]=vis[u]+1;
                q.push(mp[i+u]);
            }
        }
    }
    cout<<vis[100]-1<<"\n";
    return 0;
}
