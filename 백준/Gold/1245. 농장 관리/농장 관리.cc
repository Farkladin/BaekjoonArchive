#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int arr[103][103];
bool vis[103][103];
constexpr int dx[8]={-1,1,0,0,-1,1,-1,1},dy[8]={0,0,-1,1,-1,-1,1,1};
int N,M;
int ff(int x0,int y0){
    queue<pair<int,int> >q;q.push({x0,y0});
    vis[x0][y0]=true;
    int ret=1;
    while(!q.empty()){
        auto u=q.front();q.pop();
        for(int i=0;i<8;i++){
            int x=dx[i]+u.fi,y=dy[i]+u.se;
            if(arr[x][y]>arr[u.fi][u.se])ret=0;
            if(x<=N&&x>=1&&y<=M&&y>=1&&arr[x][y]==arr[u.fi][u.se]&&!vis[x][y]){
                vis[x][y]=true;
                q.push({x,y});
            }
        }
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++)cin>>arr[i][j];
    }
    int ans=0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(!vis[i][j]){
                ans+=ff(i,j);
            }
        }
    }
    cout<<ans<<"\n";
    
    return 0;
}
