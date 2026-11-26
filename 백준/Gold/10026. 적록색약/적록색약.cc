#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
constexpr int dx[6]={-1,1,0,0,0},dy[6]={0,0,-1,1,0,0},dz[6]={0,0,0,0,-1,1};
char arr[103][103];
int vis1[103][103],vis2[103][103];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++)cin>>arr[i][j];
    }
    auto f=[&N](int x0,int y0){
        queue<array<int,2> >q;q.push({x0,y0});
        vis1[x0][y0]=1;
        while(!q.empty()){
            auto [x_,y_]=q.front();q.pop();
            for(int i=0;i<4;i++){
                int x=x_+dx[i],y=y_+dy[i];
                if(1<=x&&x<=N&&1<=y&&y<=N&&(arr[x][y]=='B')==(arr[x_][y_]=='B')&&!vis1[x][y]){
                    vis1[x][y]=1;
                    q.push({x,y});
                }
            }
        }
    };
    auto g=[&N](int x0,int y0){
        queue<array<int,2> >q;q.push({x0,y0});
        vis2[x0][y0]=1;
        while(!q.empty()){
            auto [x_,y_]=q.front();q.pop();
            for(int i=0;i<4;i++){
                int x=x_+dx[i],y=y_+dy[i];
                if(1<=x&&x<=N&&1<=y&&y<=N&&arr[x][y]==arr[x_][y_]&&!vis2[x][y]){
                    vis2[x][y]=1;
                    q.push({x,y});
                }
            }
        }
    };
    int cnt1=0,cnt2=0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(!vis1[i][j]){
                cnt1++;
                f(i,j);
            }
            if(!vis2[i][j]){
                cnt2++;
                g(i,j);
            }
        }
    }
    cout<<cnt2<<" "<<cnt1<<"\n";
    
    return 0;
}
