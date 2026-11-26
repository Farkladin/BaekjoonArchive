#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using pii=pair<int,int>;
constexpr int dx[8]={0,-1,-1,-1,0,1,1,1},dy[8]={-1,-1,0,1,1,1,0,-1};
int arr[53][53];
bool brr[53][53];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,M;cin>>N>>M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++)cin>>arr[i][j];
    }

    vector<pii>vp={{N,1},{N,2},{N-1,1},{N-1,2}};
    while(M--){
        int d,s;cin>>d>>s;
        for(auto [xc,yc]:vp){
            int x=(xc+dx[d-1]*s+N*50-1)%N+1,y=(yc+dy[d-1]*s+N*50-1)%N+1;
            arr[x][y]++;
            brr[x][y]=true;
        }
        for(auto [xc,yc]:vp){
            int x=(xc+dx[d-1]*s+N*50-1)%N+1,y=(yc+dy[d-1]*s+N*50-1)%N+1;
            int cnt=0;
            for(int i=1;i<=7;i+=2){
                int X=x+dx[i],Y=y+dy[i];
                if(1<=X&&X<=N&&1<=Y&&Y<=N&&arr[X][Y]>0)cnt++;
            }
            arr[x][y]+=cnt;
        }
        vp.clear();
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if(arr[i][j]>=2&&!brr[i][j]){
                    vp.push_back({i,j});
                    arr[i][j]-=2;
                }
                brr[i][j]=false;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            ans+=arr[i][j];
        }
    }
    cout<<ans<<"\n";
    return 0;
}
