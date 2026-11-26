#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int arr[103][103],mx[103][103][4];
constexpr int dx[4]={0,0,-1,1},dy[4]={-1,1,0,0};
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>arr[i][j];
            mx[i][j][0]=max(mx[i][j-1][0],arr[i][j]);
            mx[i][j][2]=max(mx[i-1][j][2],arr[i][j]);
        }
        for(int j=N;j>0;j--){
            mx[i][j][1]=max(mx[i][j+1][1],arr[i][j]);
        }
    }
    int ans=0;
    for(int i=N;i>0;i--){
        for(int j=1;j<=N;j++){
            mx[i][j][3]=max(mx[i+1][j][3],arr[i][j]);
            bool flag=false;
            for(int k=0;k<4;k++){
                int x=i+dx[k],y=j+dy[k];
                flag|=arr[i][j]>mx[x][y][k];
            }
            ans+=flag;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
