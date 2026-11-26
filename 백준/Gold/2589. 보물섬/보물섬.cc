#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
char arr[53][53];
constexpr int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
int vis[53][53];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int L,W;cin>>L>>W;
    for(int i=1;i<=L;i++){
        for(int j=1;j<=W;j++)cin>>arr[i][j];
    }
    int ans=0;
    for(int i=1;i<=L;i++){
        for(int j=1;j<=W;j++){
            if(arr[i][j]=='W')continue;
            queue<pair<int,int> >q;q.push({i,j});
            memset(vis,0,sizeof(vis));
            vis[i][j]=1;
            int cur=0;
            while(!q.empty()){
                auto [xc,yc]=q.front();q.pop();
                for(int i=0;i<4;i++){
                    int x=xc+dx[i],y=yc+dy[i];
                    if(1<=x&&x<=L&&1<=y&&y<=W&&!vis[x][y]&&arr[x][y]=='L'){
                        vis[x][y]=vis[xc][yc]+1;
                        cur=max(cur,vis[xc][yc]);
                        q.push({x,y});
                    }
                }
            }
            ans=max(ans,cur);
        }
    }
    cout<<ans<<"\n";
    return 0;
}
