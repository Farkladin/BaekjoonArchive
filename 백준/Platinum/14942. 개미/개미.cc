#include "bits/stdc++.h"
using namespace std;

int spt[100003][33],dep[100003],dist[100003];
vector<pair<int,int> >G[100003];

void bfs(int x0){
    queue<int>q;q.push(x0);
    dep[x0]=1;
    while(!q.empty()){
        int x=q.front();q.pop();
        for(auto [y,w]:G[x]){
            if(dep[y])continue;
            dep[y]=dep[x]+1;
            dist[y]=dist[x]+w;
            q.push(y);
            
            int k=x,r=0;
            spt[y][r]=x;
            while(spt[k][r]){
                spt[y][r+1]=spt[k][r];
                k=spt[k][r];
                r++;
            }
        }
    }
}


int arr[100003];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;cin>>n;
    for(int i=1;i<=n;++i)cin>>arr[i];
    for(int i=1;i<n;++i){
        int a,b,c;cin>>a>>b>>c;
        G[a].emplace_back(b,c);
        G[b].emplace_back(a,c);
    }
    
    bfs(1);
    
    cout<<"1\n";
    for(int i=2;i<=n;++i){
        int energy=arr[i],u=i;
        while(spt[u][0] && dist[u]-dist[spt[u][0]]<=energy){
            int j;
            for(j=0; spt[u][j+1] && dist[u]-dist[spt[u][j+1]]<=energy; ++j);
            energy-=dist[u]-dist[spt[u][j]];
            u=spt[u][j];
        }
        cout<<u<<"\n";
    }
    
    return 0;
}
