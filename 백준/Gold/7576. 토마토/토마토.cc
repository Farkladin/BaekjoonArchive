#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
constexpr int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
int arr[1003][1003];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,M;cin>>M>>N;
    queue<pair<int,int> >q;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>arr[i][j];
            if(arr[i][j]==1){
                q.push({i,j});
            }
        }
    }
    int ans=0;
    while(!q.empty()){
        auto u=q.front();q.pop();
        for(int i=0;i<4;i++){
            int x=u.fi+dx[i],y=u.se+dy[i];
            if(1<=x&&x<=N&&1<=y&&y<=M&&!arr[x][y]){
                arr[x][y]=arr[u.fi][u.se]+1;
                ans=max(ans,arr[x][y]-1);
                q.push({x,y});
            }
        }
    }
    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(!arr[i][j]){
                cout<<"-1\n";
                return 0;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}
