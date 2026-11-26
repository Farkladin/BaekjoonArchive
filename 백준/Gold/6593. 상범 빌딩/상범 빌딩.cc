#include "bits/stdc++.h"
#include <print>
using namespace std;
using ll=long long;
#define fi first
#define se second

constexpr int dx[6]={-1,1,0,0,0,0},dy[6]={0,0,-1,1,0,0},dz[6]={0,0,0,0,-1,1};
char arr[33][33][33];
int dist[33][33][33];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    using tri=array<int,3>;
    tri src,sink;
    while(1){
        int L,R,C;cin>>L>>R>>C;
        if(L==0&&R==0&&C==0)break;
        
        for(int i=1;i<=L;i++){
            for(int j=1;j<=R;j++){
                for(int k=1;k<=C;k++){
                    char &cur=arr[i][j][k];
                    cin>>cur;
                    if(cur=='S')src={i,j,k};
                    else if(cur=='E')sink={i,j,k};
                }
            }
        }
        
        queue<tri>q;q.push(src);
        arr[src[0]][src[1]][src[2]]='#';
        memset(dist,-1,sizeof(dist));
        dist[src[0]][src[1]][src[2]]=0;
        while(!q.empty()){
            auto [xc,yc,zc]=q.front();q.pop();
            for(int i=0;i<6;i++){
                int x=xc+dx[i],y=yc+dy[i],z=zc+dz[i];
                if(1<=x&&x<=L&&1<=y&&y<=R&&1<=z&&z<=C&&arr[x][y][z]!='#'){
                    arr[x][y][z]='#';
                    dist[x][y][z]=dist[xc][yc][zc]+1;
                    q.push({x,y,z});
                }
            }
        }
        
        int ans=dist[sink[0]][sink[1]][sink[2]];
        if(ans==-1)print("Trapped!\n");
        else print("Escaped in {:d} minute(s).\n",ans);
    }
    
    return 0;
}
