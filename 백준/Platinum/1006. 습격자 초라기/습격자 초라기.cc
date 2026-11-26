#include "bits/stdc++.h"
using namespace std;

int dp[100003][4], N, W, arr[100003][2];
constexpr int NO=0, IN=1, OUT=2, BOTH=3;
int f(int i, int j){
    int &ret = dp[i][j];
    
    if(i==N)return 0;
    if(ret)return ret;
    ret=f(i+1,BOTH)+2;
    if(arr[i+1][1]==0 && arr[i+1][0]==0)ret=min(ret,f(i+1,NO));
    switch(j){
        case IN:{
            if(arr[i+1][0]+arr[i][0]<=W){
                if(arr[i+1][1]==0)ret=min(ret,f(i+1,NO));
                else ret = min(ret, f(i+1,OUT)+1);
            }
            break;
        }
        case OUT:{
            if(arr[i+1][1]+arr[i][1]<=W){
                if(arr[i+1][0]==0)ret = min(ret, f(i+1,NO));
                else ret = min(ret, f(i+1,IN)+1);
            }
            break;
        }
        case BOTH:{
            if(arr[i+1][1]+arr[i][1]<=W){
                if(arr[i+1][0]==0)ret = min(ret, f(i+1,NO));
                else ret = min(ret, f(i+1,IN)+1);
            }
            if(arr[i+1][0]+arr[i][0]<=W){
                if(arr[i+1][1]==0)ret=min(ret,f(i+1,NO));
                else ret = min(ret, f(i+1,OUT)+1);
            }
            if(arr[i+1][0]+arr[i][0]<=W && arr[i+1][1]+arr[i][1]<=W)ret = min(ret, f(i+1,NO));
            break;
        }
    }
    if(arr[i+1][0]+arr[i+1][1]<=W)ret = min(ret, f(i+1,NO)+1);
    
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int T;cin>>T;
    while(T--){
        cin>>N>>W;
        for(int i=1; i<=N; ++i) cin>>arr[i][0];
        for(int i=1; i<=N; ++i) cin>>arr[i][1];
        
        int ans=f(1,BOTH)+2;
        memset(dp,0,sizeof(dp));
        
        if(arr[N][0]+arr[1][0]<=W){
            int a=arr[N][0], b=arr[1][0];
            arr[N][0]=0; arr[1][0]=0;
            ans=min(ans,f(1,OUT)+2);
            arr[N][0]=a; arr[1][0]=b;
            memset(dp,0,sizeof(dp));
        }
        
        if(arr[N][1]+arr[1][1]<=W){
            int a=arr[N][1], b=arr[1][1];
            arr[N][1]=0; arr[1][1]=0;
            ans=min(ans,f(1,IN)+2);
            arr[N][1]=a; arr[1][1]=b;
            memset(dp,0,sizeof(dp));
        }
        
        if(arr[N][0]+arr[1][0]<=W && arr[N][1]+arr[1][1]<=W){
            int a=arr[N][0], b=arr[1][0], c=arr[N][1], d=arr[1][1];
            arr[N][0]=0; arr[1][0]=0; arr[N][1]=0; arr[1][1]=0;
            ans=min(ans,f(1,NO)+2);
            arr[N][0]=a; arr[1][0]=b; arr[N][1]=c; arr[1][1]=d;
            memset(dp,0,sizeof(dp));
        }
        
        if(arr[1][0] + arr[1][1] <=W){
            ans=min(ans, f(1,NO)+1);
            memset(dp,0,sizeof(dp));
        }
        
        cout<<ans<<"\n";
    }
    
    return 0;
}
