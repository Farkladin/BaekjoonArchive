#include <iostream>
#include <memory>
#include <utility>
#include <deque>

#define fi first
#define se second

using namespace std;

using ll=long long;

int dist[503][503],arr[503][503];
constexpr int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    while(N--){
        int X1,Y1,X2,Y2;cin>>X1>>Y1>>X2>>Y2;
        if(X1>X2)swap(X1,X2);
        if(Y1>Y2)swap(Y1,Y2);
        for(int i=X1;i<=X2;i++){
            for(int j=Y1;j<=Y2;j++)arr[i][j]=1;
        }
    }
    
    int M;cin>>M;
    while(M--){
        int X1,Y1,X2,Y2;cin>>X1>>Y1>>X2>>Y2;
        if(X1>X2)swap(X1,X2);
        if(Y1>Y2)swap(Y1,Y2);
        for(int i=X1;i<=X2;i++){
            for(int j=Y1;j<=Y2;j++)arr[i][j]=2;
        }
    }
    
    deque<pair<int,int> >dq;dq.push_front({0,0});
    for(int i=0;i<=500;i++){
        fill(dist[i],dist[i]+501,1e9);
    }
    dist[0][0]=0;
    
    while(!dq.empty()){
        auto [xc,yc]=dq.front();dq.pop_front();
        for(int i=0;i<4;i++){
            int x=xc+dx[i],y=yc+dy[i];
            if(0<=x&&x<=500&&0<=y&&y<=500&&(arr[x][y]!=2||arr[xc][yc]==2)){
                if(dist[x][y]>dist[xc][yc]+arr[x][y]){
                    dist[x][y]=dist[xc][yc]+arr[x][y];
                    if(arr[x][y])dq.push_back({x,y});
                    else dq.push_front({x,y});
                }
            }
        }
    }
    
    if(dist[500][500]==1e9)dist[500][500]=-1;
    cout<<dist[500][500]<<"\n";
    
    return 0;
}
