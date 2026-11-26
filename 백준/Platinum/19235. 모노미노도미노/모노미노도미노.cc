#include "bits/stdc++.h"
using namespace std;
using pii = pair<int,int>;

constexpr int block[5][2][2]={
    {},
    {
        {1,0},
        {0,0}
    },
    {
        {1,1},
        {0,0}
    },
    {
        {1,0},
        {1,0}
    }
};

const pii blockSize[5]={
    pii{0,0},
    pii{1,1},
    pii{1,2},
    pii{2,1}
};

int arr[22][22],n=0;
bool canPlace(int t,int x,int y){
    for(int i=0; i<2; ++i){
        for(int j=0; j<2; ++j){
            if(block[t][i][j] && arr[x+i][y+j])return false;
        }
    }
    
    return true;
}

void place(int t,int x,int y){
    ++n;
    for(int i=0; i<blockSize[t].first; ++i){
        for(int j=0; j<blockSize[t].second; ++j){
            arr[x+i][y+j]=block[t][i][j]*n;
        }
    }
}

void move2blue(int t,int x,int y){
    while(y+blockSize[t].second<=9 && canPlace(t,x,y+1))++y;
    place(t,x,y);
}

void move2green(int t,int x,int y){
    while(x+blockSize[t].first<=9 && canPlace(t,x+1,y))++x;
    place(t,x,y);
}

void alignLightGreen(){
    int c=11;
    for(int i=4; i<=5; ++i){
        for(int j=0; j<=3; ++j){
            if(arr[i][j]) c=min(c,i);
        }
    }
    
    if(c==11){
        return;
    }else if(c==4){
        for(int i=7; i>=4; --i){
            for(int j=0; j<=3; ++j){
                arr[i+2][j] = arr[i][j];
            }
        }
    }else if(c==5){
        for(int i=8; i>=5; --i){
            for(int j=0; j<=3; ++j){
                arr[i+1][j] = arr[i][j];
            }
        }
    }
    for(int i=4; i<=5; ++i){
        for(int j=0; j<=3; ++j){
            arr[i][j]=0;
        }
    }
}

void alignLightBlue(){
    int c=11;
    for(int i=0; i<=3; ++i){
        for(int j=4; j<=5; ++j){
            if(arr[i][j])c=min(c,j);
        }
    }
    
    if(c==11){
        return;
    }else if(c==4){
        for(int j=7; j>=4; --j){
            for(int i=0; i<=3; ++i){
                arr[i][j+2] = arr[i][j];
            }
        }
    }else if(c==5){
        for(int j=8; j>=5; --j){
            for(int i=0; i<=3; ++i){
                arr[i][j+1] = arr[i][j];
            }
        }
    }
    
    for(int i=0; i<=3; ++i){
        for(int j=4; j<=5; ++j){
            arr[i][j]=0;
        }
    }
}

int ans=0;
bool alignGreen(){
    bool ret=false;
    for(int i=9; i>=6; --i){
        if((arr[i][0] && arr[i][1] && arr[i][2] && arr[i][3]) || (!arr[i][0] && !arr[i][1] && !arr[i][2] && !arr[i][3])){
            if(arr[i][0] && arr[i][1] && arr[i][2] && arr[i][3]){
                ++ans;
                ret=true;
            }
            arr[i][0]=arr[i-1][0];
            arr[i][1]=arr[i-1][1];
            arr[i][2]=arr[i-1][2];
            arr[i][3]=arr[i-1][3];
            arr[i-1][0]=arr[i-1][1]=arr[i-1][2]=arr[i-1][3]=0;
        }
    }
    return ret;
}

bool alignBlue(){
    bool ret=false;
    for(int i=9; i>=6; --i){
        if((arr[0][i] && arr[1][i] && arr[2][i] && arr[3][i]) || (!arr[0][i] && !arr[1][i] && !arr[2][i] && !arr[3][i])){
            if(arr[0][i] && arr[1][i] && arr[2][i] && arr[3][i]){
                ++ans;
                ret=true;
            }
            arr[0][i]=arr[0][i-1];
            arr[1][i]=arr[1][i-1];
            arr[2][i]=arr[2][i-1];
            arr[3][i]=arr[3][i-1];
            arr[0][i-1]=arr[1][i-1]=arr[2][i-1]=arr[3][i-1]=0;
        }
    }
    return ret;
}

bool moveInGreen(){
    bool ret=false;
    for(int i=9; i>=5; --i){
        for(int j=0;j<=3; ++j){
            if(!arr[i][j] && arr[i-1][j]){
                if(arr[i-1][j]!=arr[i-1][j+1] && (j==0 || arr[i-1][j]!=arr[i-1][j-1])){
                    arr[i][j]=arr[i-1][j];
                    arr[i-1][j]=0;
                    ret=true;
                }else if(arr[i-1][j]==arr[i-1][j+1] && !arr[i][j+1]){
                    arr[i][j]=arr[i-1][j];
                    arr[i][j+1]=arr[i-1][j+1];
                    arr[i-1][j]=arr[i-1][j+1]=0;
                    ret=true;
                }
            }
        }
    }
    return ret;
}

bool moveInBlue(){
    bool ret=false;
    for(int i=9; i>=5; --i){
        for(int j=0;j<=3; ++j){
            if(!arr[j][i] && arr[j][i-1]){
                if(arr[j][i-1]!=arr[j+1][i-1] && (j==0 || arr[j][i-1]!=arr[j-1][i-1])){
                    arr[j][i]=arr[j][i-1];
                    arr[j][i-1]=0;
                    ret=true;
                }else if(arr[j][i-1]==arr[j+1][i-1] && !arr[j+1][i]){
                    arr[j][i]=arr[j][i-1];
                    arr[j+1][i]=arr[j+1][i-1];
                    arr[j][i-1]=arr[j+1][i-1]=0;
                    ret=true;
                }
            }
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N; cin>>N;
    while(N--){
        int t,x,y; cin>>t>>x>>y;
        bool flag;
        move2blue(t,x,y);
        do{
            flag=false;
            while(alignBlue());
            while(moveInBlue())flag=true;
        }while(flag);
        alignLightBlue();
        
        move2green(t, x, y);
        do{
            flag=false;
            while(alignGreen());
            while(moveInGreen())flag=true;
        }while(flag);
        alignLightGreen();
    }
    
    cout<<ans<<"\n";
    ans=0;
    for(int i=6;i<=9;++i){
        ans+=(arr[i][0]>0)+(arr[i][1]>0)+(arr[i][2]>0)+(arr[i][3]>0)+(arr[0][i]>0)+(arr[1][i]>0)+(arr[2][i]>0)+(arr[3][i]>0);
    }
    cout<<ans<<"\n";
    return 0;
}
