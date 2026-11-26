#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
constexpr int dx[6]={-1,1,0,0,0},dy[6]={0,0,-1,1,0,0},dz[6]={0,0,0,0,-1,1};
int arr[103][103][103];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int M,N,H;cin>>M>>N>>H;
    queue<array<int,3> >q;
    for(int k=1;k<=H;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=M;j++){
                cin>>arr[i][j][k];
                if(arr[i][j][k]==1){
                    q.push({i,j,k});
                }
            }
        }
    }
    int ans=0;
    while(!q.empty()){
        auto [x_,y_,z_]=q.front();q.pop();
        for(int i=0;i<6;i++){
            int x=x_+dx[i],y=y_+dy[i],z=z_+dz[i];
            if(1<=x&&x<=N&&1<=y&&y<=M&&1<=z&&z<=H&&!arr[x][y][z]){
                arr[x][y][z]=arr[x_][y_][z_]+1;
                q.push({x,y,z});
                ans=max(ans,arr[x][y][z]-1);
            }
        }
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            for(int k=1;k<=H;k++){
                if(!arr[i][j][k]){
                    cout<<"-1\n";
                    return 0;
                }
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}
