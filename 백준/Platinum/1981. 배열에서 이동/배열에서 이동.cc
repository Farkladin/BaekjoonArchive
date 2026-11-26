#include "bits/stdc++.h"
using namespace std;

int arr[103][103],n;
int8_t brr[103][103];
constexpr array<pair<int,int>,4>ds{{{1,0},{-1,0},{0,-1},{0,1}}};

bool g(int ub,int lb){
    if(lb>arr[1][1])return false;
    memset(brr,0,sizeof(brr));
    queue<pair<int,int> >q; q.push({1,1});
    brr[1][1]=1;
    
    while(!q.empty()){
        auto [xx,yy] = q.front(); q.pop();
        for(auto [dx,dy]:ds){
            int x=xx+dx, y=yy+dy;
            if(x>=1 && x<=n && y>=1 && y<=n && !brr[x][y] && arr[x][y]<=ub && arr[x][y]>=lb){
                brr[x][y]=1;
                q.push({x,y});
            }
        }
    }
    
    return brr[n][n]==1;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>arr[i][j];
        }
    }
    
    int ans=1e9;
    for(int ub=0;ub<=200;ub++){
        if(ub<arr[1][1])continue;
        int l=0,r=ub,mid;
        while(l<=r){
            mid=(l+r)>>1;
            if(g(ub,mid)){
                ans=min(ans,ub-mid);
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
    }
    
    cout<<ans<<"\n";
    
    return 0;
}
