#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using lf=double;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;
using ppp=pair<pii,pii>;

vector<int>Hungarian(int A[][503],const int &n,const int &m){
    vector<int>u(n+2),v(m+2),p(m+2),way(m+2),ans(n+2);
    for(int i=1;i<=n;i++){
        p[0]=i;
        int j0=0;
        vector<int>minv(m+2,1e9);
        vector<bool>vis(m+2,false);
        do{
            vis[j0]=true;
            int i0=p[j0],delta=1e9,j1=0;
            for(int j=1;j<=m;j++){
                if(!vis[j]){
                    int cur=A[i0][j]-u[i0]-v[j];
                    if(cur<minv[j]){
                        minv[j]=cur;
                        way[j]=j0;
                    }
                    if(minv[j]<delta){
                        delta=minv[j];
                        j1=j;
                    }
                }
            }
            
            for(int j=0;j<=m;j++){
                if(vis[j]){
                    u[p[j]]+=delta;
                    v[j]-=delta;
                }else{
                    minv[j]-=delta;
                }
            }
            j0=j1;
        }while(p[j0]);
        
        do{
            int j1=way[j0];
            p[j0]=p[j1];
            j0=j1;
        }while(j0);
    }
    
    for(int j=1;j<=m;j++){
        ans[p[j]]=j;
    }
    
    return ans;
}

int arr[503][503];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++)cin>>arr[i][j];
    }
    
    auto res=Hungarian(arr,N,N);
    
    int ans=0;
    for(int i=1;i<=N;i++){
        ans+=arr[i][res[i]];
    }
    cout<<ans<<"\n";
    return 0;
}
