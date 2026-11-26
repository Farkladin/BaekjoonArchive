#include "bits/stdc++.h"
using namespace std;
using ll=long long;
int arr[203][203];
constexpr int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,K;cin>>N>>K;
    using quad=array<int,4>;
    priority_queue<quad>pq;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>arr[i][j];
            if(arr[i][j])pq.push({0,-arr[i][j],i,j});
        }
    }
    int S,X,Y;cin>>S>>X>>Y;
    
    while(!pq.empty()){
        auto [t,num,xc,yc]=pq.top();pq.pop();
        if(-t>=S)continue;
        for(int i=0;i<4;i++){
            int x=xc+dx[i],y=yc+dy[i];
            if(1<=x&&x<=N&&1<=y&&y<=N&&!arr[x][y]){
                arr[x][y]=-num;
                pq.push({t-1,num,x,y});
            }
        }
    }
    cout<<arr[X][Y]<<"\n";
    return 0;
}
