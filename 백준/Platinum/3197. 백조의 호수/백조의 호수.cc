#include "bits/stdc++.h"
using namespace std;
char arr[1503][1503];
const array<pair<int,int>, 4> ds{{{-1,0},{1,0},{0,-1},{0,1}}};
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int R,C;cin>>R>>C;
    queue<pair<int,int> >swan,water;
    char cnt=0;
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            cin>>arr[i][j];
            if(arr[i][j]=='L'){
                swan.push({i,j});
                arr[i][j]=cnt++;
            }
            if(arr[i][j]!='X')water.push({i,j});
        }
    }
    
    int ans=0;
    loop:{
        set<pair<int,int> >stk;
        while(!swan.empty()){
            auto [xx,yy] = swan.front(); swan.pop();
            for(auto [dx,dy]:ds){
                int x=xx+dx,y=yy+dy;
                if(x>R || x<1 || y>C || y<1) continue;
                if(arr[x][y]==(arr[xx][yy]^1)){
                    cout<<ans<<"\n";
                    return 0;
                }
                if(arr[x][y]=='.'){
                    arr[x][y]=arr[xx][yy];
                    swan.push({x,y});
                }else if(arr[x][y]=='X'){
                    stk.insert({xx,yy});
                }
            }
        }
        
        for(auto p:stk)swan.push(p);
        stk.clear();
        
        while(!water.empty()){
            auto [xx,yy] = water.front(); water.pop();
            for(auto [dx,dy]:ds){
                int x=xx+dx,y=yy+dy;
                if(x>R || x<1 || y>C || y<1) continue;
                if(arr[x][y]=='X'){
                    arr[x][y]='.';
                    stk.insert({x,y});
                }
            }
        }
        
        for(auto p:stk)water.push(p);
        stk.clear();
        
        ans++;
        
    }goto loop;
    
    return 0;
}
