#include "bits/stdc++.h"
using namespace std;
using pii = pair<int,int>;
int house[22][22],dt[22][22],wall[22][22][4],dtt[22][22], R,C,K;
int8_t vis[22][22];

vector<pair<int,int> > wPoint;
vector<array<int,3> > heater;


constexpr array<pair<int,int>, 4> ds={pii{0,1}, pii{0,-1}, pii{-1,0}, pii{1,0}};

void f(int x,int y,int dir){
    queue<array<int,3> >q;
    memset(vis,0,sizeof(vis));
    
    if(wall[x][y][dir]==0){
        q.push({x+ds[dir].first, y+ds[dir].second, 5});
        vis[q.front()[0]][q.front()[1]]=1;
        dt[q.front()[0]][q.front()[1]] += 5;
    }
    
    while(!q.empty()){
        auto [x0,y0,w] = q.front(); q.pop();
        if(x0<=0 || x0>R || y0<=0 || y0>C || w<=1) continue;
        switch(dir){
            case 0:
                if(wall[x0][y0][0]==0 && vis[x0][y0+1]==0){
                    vis[x0][y0+1]=1;
                    dt[x0][y0+1]+=w-1;
                    q.push({x0,y0+1,w-1});
                }
                if(wall[x0][y0][2]==0 && wall[x0-1][y0][0]==0 && vis[x0-1][y0+1]==0){
                    vis[x0-1][y0+1]=1;
                    dt[x0-1][y0+1]+=w-1;
                    q.push({x0-1,y0+1,w-1});
                }
                if(wall[x0][y0][3]==0 && wall[x0+1][y0][0]==0 && vis[x0+1][y0+1]==0){
                    vis[x0+1][y0+1]=1;
                    dt[x0+1][y0+1]+=w-1;
                    q.push({x0+1,y0+1,w-1});
                }
                break;
            case 1:
                if(wall[x0][y0][1]==0 && vis[x0][y0-1]==0){
                    vis[x0][y0-1]=1;
                    dt[x0][y0-1]+=w-1;
                    q.push({x0,y0-1,w-1});
                }
                if(wall[x0][y0][2]==0 && wall[x0-1][y0][1]==0 && vis[x0-1][y0-1]==0){
                    vis[x0-1][y0-1]=1;
                    dt[x0-1][y0-1]+=w-1;
                    q.push({x0-1,y0-1,w-1});
                }
                if(wall[x0][y0][3]==0 && wall[x0+1][y0][1]==0 && vis[x0+1][y0-1]==0){
                    vis[x0+1][y0-1]=1;
                    dt[x0+1][y0-1]+=w-1;
                    q.push({x0+1,y0-1,w-1});
                }
                break;
            case 2:
                if(wall[x0][y0][2]==0 && vis[x0-1][y0]==0){
                    vis[x0-1][y0]=1;
                    dt[x0-1][y0]+=w-1;
                    q.push({x0-1,y0,w-1});
                }
                if(wall[x0][y0][0]==0 && wall[x0][y0+1][2]==0 && vis[x0-1][y0+1]==0){
                    vis[x0-1][y0+1]=1;
                    dt[x0-1][y0+1]+=w-1;
                    q.push({x0-1,y0+1,w-1});
                }
                if(wall[x0][y0][1]==0 && wall[x0][y0-1][2]==0 && vis[x0-1][y0-1]==0){
                    vis[x0-1][y0-1]=1;
                    dt[x0-1][y0-1]+=w-1;
                    q.push({x0-1,y0-1,w-1});
                }
                break;
            case 3:
                if(wall[x0][y0][3]==0 && vis[x0+1][y0]==0){
                    vis[x0+1][y0]=1;
                    dt[x0+1][y0]+=w-1;
                    q.push({x0+1,y0,w-1});
                }
                if(wall[x0][y0][0]==0 && wall[x0][y0+1][3]==0 && vis[x0+1][y0+1]==0){
                    vis[x0+1][y0+1]=1;
                    dt[x0+1][y0+1]+=w-1;
                    q.push({x0+1,y0+1,w-1});
                }
                if(wall[x0][y0][1]==0 && wall[x0][y0-1][3]==0 && vis[x0+1][y0-1]==0){
                    vis[x0+1][y0-1]=1;
                    dt[x0+1][y0-1]+=w-1;
                    q.push({x0+1,y0-1,w-1});
                }
                break;
            default:
                assert(false);
                break;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin>>R>>C>>K;
    for(int i=1;i<=R;++i){
        for(int j=1;j<=C;++j){
            int x;cin>>x;
            if(x==5)wPoint.emplace_back(i,j);
            else if(x)heater.push_back({i,j,x-1});
        }
    }
    
    int W;cin>>W;
    while(W--){
        int x,y,t;cin>>x>>y>>t;
        if(t==0){
            wall[x][y][2]=1;
            wall[x-1][y][3]=1;
        }else{
            wall[x][y][0]=1;
            wall[x][y+1][1]=1;
        }
    }
    
    for(auto [x,y,dir]:heater){
        f(x,y,dir);
    }
    
    int cnt=0;
    Loop:{
        ++cnt;
        if(cnt>=101){
            cout<<cnt<<"\n";
            return 0;
        }
        
        for(int i=1;i<=R;++i){
            for(int j=1;j<=C;++j){
                house[i][j] += dt[i][j];
            }
        }
        
        memset(dtt,0,sizeof(dtt));
        for(int i=1;i<=R;++i){
            for(int j=1;j<=C;j++){
                for(int dir=0; dir<4; ++dir){
                    if(wall[i][j][dir]==0){
                        auto [dx,dy] = ds[dir];
                        int x=i+dx, y=j+dy;
                        if(1<=x&&x<=R && 1<=y&&y<=C){
                            dtt[i][j] += (house[x][y] - house[i][j])/4;
                        }
                    }
                }
            }
        }
        
        for(int i=1;i<=R;++i){
            for(int j=1;j<=C;++j){
                house[i][j] += dtt[i][j];
            }
        }
        
        for(int i=1;i<=R;++i){
            --house[i][1];
            --house[i][C];
        }
        for(int i=2;i<C;++i){
            --house[1][i];
            --house[R][i];
        }
        
        
        for(int i=1;i<=R;++i){
            for(int j=1;j<=C;++j){
                house[i][j] = max(house[i][j],0);
            }
        }
        
        int8_t failed = 0;
        for(auto [x,y]:wPoint){
            failed |= house[x][y]<K;
        }
        
        if(!failed){
            cout<<cnt<<"\n";
            return 0;
        }
    }goto Loop;
    
    return 0;
}
