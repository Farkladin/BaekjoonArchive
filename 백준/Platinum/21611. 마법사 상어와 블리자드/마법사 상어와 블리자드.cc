#include "bits/stdc++.h"
using namespace std;
using pii=pair<int,int>;

int arr[55][55],vis[55][55],countBeads[10];
pii nxt[55][55],pre[55][55];
constexpr array<pair<int,int>, 4>ds{pii{-1,0},pii{1,0},pii{0,-1},pii{0,1}};
constexpr array<int, 4> nxtDir{2,3,1,0}, preDir{3,2,0,1};

void makeLink(const int &N){
    const int mid=(N+1)>>1;
    int x=mid,y=mid,dir=1,cnt=2;
    vis[x][y]=1;
    nxt[x][y]=pii{x,y-1};
    pre[x][y-1]=pii{x,y};
    vis[x][--y]=2;
    while(x!=1 || y!=1){
        dir=nxtDir[dir];
        auto [dx,dy]=ds[dir];
        if(vis[x+dx][y+dy])dir=preDir[dir];
        dx=ds[dir].first;
        dy=ds[dir].second;
        
        nxt[x][y]=pii{x+dx,y+dy};
        pre[x+dx][y+dy]=pii{x,y};
        x+=dx;
        y+=dy;
        vis[x][y]=++cnt;
    }
}

void moveBead(int x,int y, const int &mid){
    auto [xx,yy]=pre[x][y];
    while(arr[xx][yy]==0 && (xx!=mid || yy!=mid)){
        swap(arr[xx][yy], arr[x][y]);
        x=xx; y=yy;
        xx=pre[x][y].first;
        yy=pre[x][y].second;
    }
}

void moveBeads(int x,int y, const int &mid){
    while(x && y){
        if(arr[x][y])moveBead(x,y,mid);
        auto [nxtx,nxty] = nxt[x][y];
        x=nxtx; y=nxty;
    }
}

bool explosion(int x,int y){
    bool exploded = false;
    stack<pair<int,int> >beads;
    int k=-1;
    while(x && y){
        if(arr[x][y] != k){
            bool flag = beads.size()>=4 && k>0;
            if(flag) exploded = true;
            while(!beads.empty()){
                if(flag){
                    auto [xx,yy] = beads.top();
                    ++countBeads[k];
                    arr[xx][yy]=0;
                }
                beads.pop();
            }
            k=arr[x][y];
        }
        
        if(arr[x][y]>0)beads.push(pii{x,y});
        auto [nxtx,nxty] = nxt[x][y];
        x=nxtx; y=nxty;
    }
    
    // ONE MORE
    {
        bool flag = beads.size()>=4 && k>0;
        if(flag) exploded = true;
        while(!beads.empty()){
            if(flag){
                auto [xx,yy] = beads.top();
                ++countBeads[k];
                arr[xx][yy]=0;
            }
            beads.pop();
        }
    }
    
    return exploded;
}

void replace(int x,int y){
    const int X=x, Y=y;
    queue<int>newBeads;
    int cnt=0, k=-1;
    while(x && y){
        if(arr[x][y] != k){
            if(k>0){
                newBeads.push(cnt); // A
                newBeads.push(k);   // B
            }
            k=arr[x][y];
            cnt=0;
        }
        ++cnt;
        
        auto [nxtx,nxty] = nxt[x][y];
        x=nxtx; y=nxty;
    }
    
    if(k>0){
        newBeads.push(cnt); // A
        newBeads.push(k);   // B
    }
    
    memset(arr,0,sizeof(arr));
    
    x=nxt[X][Y].first; y=nxt[X][Y].second;
    while(x && y && !newBeads.empty()){
        int cur = newBeads.front(); newBeads.pop();
        arr[x][y]=cur;
        
        auto [nxtx,nxty] = nxt[x][y];
        x=nxtx; y=nxty;
    }
}

/* C++ 20 stuff. But BOJ Compiler does not support std::format.
void printCur(const int &N){
    for(int i=1;i<=N;++i){
        for(int j=1;j<=N;++j)cout<<format("{:>2}",arr[i][j])<<" ";
        cout<<"\n";
    }
}
*/

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int N,M; cin>>N>>M;
    const int mid=(N+1)>>1;
    makeLink(N);
    for(int i=1;i<=N;++i){
        for(int j=1;j<=N;++j)cin>>arr[i][j];
    }
    
    while(M--){
        int d,s; cin>>d>>s; --d;
        auto [dx,dy] = ds[d];
        for(int i=0,x=mid+dx,y=mid+dy; i<s && 1<=x&&x<=N && 1<=y&&y<=N; x+=dx,y+=dy,++i){
            arr[x][y]=0;
        }
        
        do{
            moveBeads(mid,mid,mid);
        }while(explosion(mid,mid));
        replace(mid,mid);
    }
    
    cout<<countBeads[1] + countBeads[2]*2 + countBeads[3]*3<<"\n";
    
    return 0;
}
