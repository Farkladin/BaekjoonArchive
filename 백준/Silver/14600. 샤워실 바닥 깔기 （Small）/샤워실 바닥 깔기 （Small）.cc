#include "bits/stdc++.h"
using namespace std;

int arr[222][222],cnt=0;
void g(int x1,int x2,int y1,int y2,int x,int y){
    ++cnt;
    for(int i=x1;i<=x2;++i){
        for(int j=y1;j<=y2;++j){
            if(!arr[i][j] && (i!=x || j!=y))arr[i][j]=cnt;
        }
    }
}

void f(int x1,int x2,int y1,int y2,int x,int y,bool flag){
    const int n=x2-x1+1;
    if(n==2){
        ++cnt;
        for(int i=x1;i<=x2;++i){
            for(int j=y1;j<=y2;++j){
                if(i!=x || j!=y)arr[i][j]=cnt;
                else if(flag)arr[i][j]=-1;
            }
        }
        return;
    }
    
    const int midx = (x1+x2)>>1, midy = (y1+y2)>>1;
    if(x<=midx){
        if(y<=midy){
            f(x1,midx,y1,midy,x,y,flag);
            f(x1,midx,midy+1,y2,midx,midy+1,false);
            f(midx+1,x2,y1,midy,midx+1,midy,false);
            f(midx+1,x2,midy+1,y2,midx+1,midy+1,false);
            g(x1,x2,y1,y2,x,y);
        }else{
            f(x1,midx,y1,midy,midx,midy,false);
            f(x1,midx,midy+1,y2,x,y,flag);
            f(midx+1,x2,y1,midy,midx+1,midy,false);
            f(midx+1,x2,midy+1,y2,midx+1,midy+1,false);
            g(x1,x2,y1,y2,x,y);
        }
    }else{
        if(y<=midy){
            f(x1,midx,y1,midy,midx,midy,false);
            f(x1,midx,midy+1,y2,midx,midy+1,false);
            f(midx+1,x2,y1,midy,x,y,flag);
            f(midx+1,x2,midy+1,y2,midx+1,midy+1,false);
            g(x1,x2,y1,y2,x,y);
        }else{
            f(x1,midx,y1,midy,midx,midy,false);
            f(x1,midx,midy+1,y2,midx,midy+1,false);
            f(midx+1,x2,y1,midy,midx+1,midy,false);
            f(midx+1,x2,midy+1,y2,x,y,flag);
            g(x1,x2,y1,y2,x,y);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int k;cin>>k;
    const int N=1<<k;
    int x,y; cin>>x>>y;
    swap(x,y);
    x=N-x+1;
    f(1,N,1,N,x,y,true);
    for(int i=1;i<=N;++i){
        for(int j=1;j<=N;++j){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
