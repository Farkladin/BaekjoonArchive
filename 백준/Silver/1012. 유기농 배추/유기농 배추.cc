#include "bits/stdc++.h"
using namespace std;
int arr[53][53];
const int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
void ff(int x0,int y0){
    queue<pair<int,int> >q;
    q.push({x0,y0});
    arr[x0][y0]=0;
    while(!q.empty()){
        auto [xx,yy]=q.front();q.pop();
        for(int i=0;i<4;i++){
            int x=xx+dx[i],y=yy+dy[i];
            if(arr[x][y]==1){
                arr[x][y]=0;
                q.push({x,y});
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    
    int T;cin>>T;
    while(T--){
        int M,N,K;cin>>M>>N>>K;
        memset(arr,0,sizeof(arr));
        while(K--){
            int x,y;cin>>x>>y;
            arr[y+1][x+1]=1;
        }
        int cnt=0;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=M;j++){
                if(arr[i][j]){
                    ff(i,j);
                    cnt++;
                }
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}
