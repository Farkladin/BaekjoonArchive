#include "bits/stdc++.h"
using namespace std;

char arr[1003][1003];
struct Type{
    int l,r;
    Type(int l=1e9, int r=1e9):l(l),r(r){}
}dist[1003][1003];

using pii = pair<int,int>;
constexpr int dx[4] = {-1,1,0,0}, dy[4]={0,0,-1,1};
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N,M,L,R; cin>>N>>M>>L>>R;
    
    deque<pii>dq;
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=M; ++j){
            cin>>arr[i][j];
            if(arr[i][j]=='2'){
                dq.push_back(pii{i,j});
                dq.push_back(pii{i,j});
                dist[i][j] = Type(0,0);
                arr[i][j]='1';
            }
        }
    }
    
    while(!dq.empty()){
        auto [x,y] = dq.front(); dq.pop_front();
        for(int i=0; i<2; ++i){
            int xx=x+dx[i], yy=y+dy[i];
            if(1<=xx&&xx<=N && 1<=yy&&yy<=M && arr[xx][yy]!='1'){
                arr[xx][yy]='1';
                dist[xx][yy] = dist[x][y];
                dq.push_front(pii{xx,yy});
            }
        }
        
        for(int i=2; i<4; ++i){
            int xx=x+dx[i], yy=y+dy[i];
            if(1<=xx&&xx<=N && 1<=yy&&yy<=M && arr[xx][yy]!='1'){
                arr[xx][yy]='1';
                dist[xx][yy] = dist[x][y];
                if(i==2) ++dist[xx][yy].l;
                else ++dist[xx][yy].r;
                dq.push_back(pii{xx,yy});
            }
        }
    }
    
    int ans=0;
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=M; ++j){
            ans += dist[i][j].l<=L && dist[i][j].r<=R;
        }
    }
    
    cout<<ans<<"\n";
    
    return 0;
}
