#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;
int arr[53][53];
constexpr int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,M;cin>>N>>M;
    int r,c,d;cin>>r>>c>>d;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++)cin>>arr[i][j];
    }
    r++;c++;
    int cnt=0;
    while(1){
        if(arr[r][c]==0){
            arr[r][c]=2;
            cnt++;
        }
        bool flag=false;
        for(int i=0;i<4;i++)flag|=arr[r+dx[i]][c+dy[i]]==0;
        
        if(flag){
            d--;
            if(d<0)d=3;
            int x=r+dx[d],y=c+dy[d];
            if(arr[x][y]==0){
                r=x;c=y;
            }
        }else{
            int bck=(d+2)%4;
            int x=r+dx[bck],y=c+dy[bck];
            if(arr[x][y]==1)break;
            else{
                r=x;
                c=y;
            }
        }
    }
    
    cout<<cnt<<"\n";
    return 0;
}
