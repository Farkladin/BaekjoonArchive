#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
constexpr int po10[5]={0,1,10,100,1000},dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
array<int,4>arr[404];
int brr[23][23];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++)brr[i][j]=-1;
    }
    for(int k=1;k<=N*N;k++){
        int a,b,c,d,e;cin>>a>>b>>c>>d>>e;
        arr[a]={b,c,d,e};
        int x=0,y=0,mx=-1,mx2=-1;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if(brr[i][j]!=-1)continue;
                int cnt=0,cnt2=0;
                for(int dir=0;dir<4;dir++){
                    int nx=dx[dir]+i,ny=dy[dir]+j;
                    cnt2+=brr[nx][ny]==-1;
                    for(int t=0;t<4;t++){
                        if(brr[nx][ny]==arr[a][t]){
                            cnt++;
                            break;
                        }
                    }
                }
                if(mx<cnt||(mx==cnt&&mx2<cnt2)){
                    mx=cnt;
                    mx2=cnt2;
                    x=i;y=j;
                }
            }
        }
        brr[x][y]=a;
    }
    
    int ans=0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            int cnt=0;
            for(int d=0;d<4;d++){
                int nx=dx[d]+i,ny=dy[d]+j;
                for(int t=0;t<4;t++){
                    if(brr[nx][ny]==arr[brr[i][j]][t]){
                        cnt++;
                        break;
                    }
                }
            }
            ans+=po10[cnt];
        }
    }
    cout<<ans<<"\n";
    return 0;
}
