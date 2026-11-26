#include "bits/stdc++.h"

using namespace std;

const int pfs[11][7][7]={
    {
        {1,0,0,0},
        {1,1,1,1},
        {1,0,0,0}
    },
    {
        {0,1,0,0},
        {1,1,1,1},
        {1,0,0,0}
    },
    {
        {0,0,1,0},
        {1,1,1,1},
        {1,0,0,0}
    },
    {
        {0,0,0,1},
        {1,1,1,1},
        {1,0,0,0}
    },
    {
        {0,1,0,0},
        {1,1,1,1},
        {0,1,0,0}
    },
    {
        {0,0,1,0},
        {1,1,1,1},
        {0,1,0,0}
    },
    {
        {0,0,1,1,1},
        {1,1,1,0,0}
    },
    {
        {0,0,1,1},
        {0,1,1,0},
        {1,1,0,0}
    },
    {
        {0,0,1,1},
        {1,1,1,0},
        {1,0,0,0}
    },
    {
        {1,1,0,0},
        {0,1,1,1},
        {0,1,0,0}
    },
    {
        {0,1,0,0},
        {1,1,1,0},
        {0,0,1,1}
    }
};

const pair<int,int> SIZE[11]={
    {3,4},
    {3,4},
    {3,4},
    {3,4},
    {3,4},
    {3,4},
    {2,5},
    {3,4},
    {3,4},
    {3,4},
    {3,4}
};

const int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};

int A[11][11][11];

bool g(int p,int x,int y,int z){
    for(int i=x;i<SIZE[p].first+x;i++){
        for(int j=y;j<SIZE[p].second+y;j++){
            if(bool(A[i][j][z])^bool(pfs[p][i-x][j-y]))return false;
        }
    }
    
    int px=0,py=0,B[11][11],C[11][11],D[11][11];
    for(int i=1;i<=6;i++){
        for(int j=1;j<=6;j++){
            if(A[i][j][z]==1){
                px=i;py=j;
            }
            B[i][j]=D[i][j]=-1;
            C[i][j]=-2;
        }
    }

    queue<pair<int,int> >q;q.push({px,py});
    B[px][py]=D[px][py]=0;
    C[px][py]=-1;

    bool stop=false;
    while(!q.empty()){
        auto u=q.front();q.pop();
        for(int i=0;i<4;i++){
            x=dx[i]+u.first;y=dy[i]+u.second;
            if(x>=1 && x<=6 && y>=1 && y<=6 && C[x][y]==-2 && A[x][y][z]){
                C[x][y]=i;
                B[x][y]=B[u.first][u.second]+(C[x][y]==C[u.first][u.second]||C[u.first][u.second]==-1);
                D[x][y]=D[u.first][u.second]+(C[x][y]!=C[u.first][u.second]&&C[u.first][u.second]!=-1);
                if((B[x][y]>=2&&D[x][y]==0)||D[x][y]>=2){
                    cout<<A[x][y][z];
                    stop=true;
                    break;
                }
                q.push({x,y});
            }
        }
        if(stop)break;
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    for(int i=1;i<=6;i++){
        for(int j=1;j<=6;j++){
            cin>>A[i][j][0];
            A[i][7-j][4]=A[i][j][0];
        }
    }
    for(int i=1;i<=6;i++){
        for(int j=1;j<=6;j++){
            A[j][7-i][1]=A[i][j][0];
            A[7-i][7-j][2]=A[i][j][0];
            A[7-j][i][3]=A[i][j][0];
            A[j][7-i][5]=A[i][j][4];
            A[7-i][7-j][6]=A[i][j][4];
            A[7-j][i][7]=A[i][j][4];
        }
    }
    
    for(int p=0;p<11;p++){
        for(int k=0;k<8;k++){
            for(int i=1;i+SIZE[p].first<=7;i++){
                for(int j=1;j+SIZE[p].second<=7;j++){
                    if(g(p,i,j,k)) {
                        return 0;
                    }
                }
            }
        }
    }
    cout<<0<<endl;
    return 0;
}
