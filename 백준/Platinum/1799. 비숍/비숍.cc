#include "bits/stdc++.h"
using namespace std;
int N,arr[13][13],k;
int f(int x,int y){
    int ret=0;
    if(y>N){
        x++;
        y=1+((x&1)^k);
    }
    if(x>N)return 0;
    ret=f(x,y+2);
    if(!arr[x][y])return ret;
    stack<pair<int,int> >stk;
    for(int i=x,j=y; i>0&&j>0; i--,j--){
        if(arr[i][j])stk.push({i,j});
        arr[i][j]=0;
        
    }
    for(int i=x,j=y; i<=N&&j<=N; i++,j++){
        if(arr[i][j])stk.push({i,j});
        arr[i][j]=0;
    }
    for(int i=x,j=y; i<=N&&j>0; i++,j--){
        if(arr[i][j])stk.push({i,j});
        arr[i][j]=0;
    }
    for(int i=x,j=y; i>0&&j<=N; i--,j++){
        if(arr[i][j])stk.push({i,j});
        arr[i][j]=0;
    }
    ret=max(ret,f(x,y+2)+1);
    while(!stk.empty()){
        auto [i,j] = stk.top(); stk.pop();
        arr[i][j]=1;
    }
    
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin>>N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++)cin>>arr[i][j];
    }
    int ans=f(1,2);
    k=1;
    ans+=f(1,1);
    cout<<ans<<"\n";
    return 0;
}
