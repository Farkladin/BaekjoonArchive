#include "bits/stdc++.h"
using namespace std;

int arr[13][13];
const int dx1[8]={-2,2,-1,1,-2,2,-1,1}, dy1[8]={-1,-1,-2,-2,1,1,2,2};
const int dx2[4]={-1,-1,1,1}, dy2[4]={-1,1,-1,1};
const int dx3[4]={-1,1,0,0}, dy3[4]={0,0,-1,1};
int dist[303][303];
long long dp[103][3];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int N; cin>>N;
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=N; ++j){
            cin>>arr[i][j];
        }
    }
    const int n = N*N;
    
    for(int i=1; i<=n*3; ++i){
        for(int j=1; j<i; ++j){
            dist[i][j]=dist[j][i]=1e9;
        }
    }
    
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=N; ++j){
            int u=arr[i][j];
            dist[u][u+n]=dist[u+n][u]=1;
            dist[u][u+n+n]=dist[u+n+n][u]=1;
            dist[u+n][u+n+n]=dist[u+n+n][u+n]=1;
            for(int dir=0; dir<8; ++dir){
                int x=dx1[dir]+i, y=dy1[dir]+j;
                int v = arr[x][y];
                if(v){
                    dist[u][v]=1;
                    dist[v][u]=1;
                }
            }
            
            u+=n;
            for(int dir=0; dir<4; ++dir){
                int x=dx2[dir]+i, y=dy2[dir]+j;
                while(1<=x&&x<=N && 1<=y&&y<=N){
                    int v = arr[x][y]+n;
                    dist[u][v]=1;
                    dist[v][u]=1;
                    
                    x+=dx2[dir]; y+=dy2[dir];
                }
            }
            
            u+=n;
            for(int dir=0; dir<4; ++dir){
                int x=dx3[dir]+i, y=dy3[dir]+j;
                while(1<=x&&x<=N && 1<=y&&y<=N){
                    int v = arr[x][y]+n+n;
                    dist[u][v]=1;
                    dist[v][u]=1;
                    x+=dx3[dir]; y+=dy3[dir];
                }
            }
        }
    }
    
    for(int k=1; k<=3*n; ++k){
        for(int i=1; i<=3*n; ++i){
            for(int j=1; j<=3*n; ++j){
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }

    
    for(int i=2; i<=n; ++i){
        int j=i+n, k=i+n+n;
        dp[i][0]=min({dp[i-1][0]+dist[i-1][i], dp[i-1][1]+dist[j-1][i], dp[i-1][2]+dist[k-1][i]});
        dp[i][1]=min({dp[i-1][0]+dist[i-1][j], dp[i-1][1]+dist[j-1][j], dp[i-1][2]+dist[k-1][j]});
        dp[i][2]=min({dp[i-1][0]+dist[i-1][k], dp[i-1][1]+dist[j-1][k], dp[i-1][2]+dist[k-1][k]});
    }
    
    cout<<min({dp[n][0],dp[n][1],dp[n][2]})<<"\n";
    return 0;
}
