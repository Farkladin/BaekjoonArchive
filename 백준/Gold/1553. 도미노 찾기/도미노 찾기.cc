#include "bits/stdc++.h"
using namespace std;
char arr[10][10];
bool use[10][10],vis[10][10];
int f(int i,int j){
    if(j>7){
        i++;
        j=1;
    }
    if(i>8)return 1;
    if(vis[i][j])return f(i,j+1);
    int ret=0;
    if(!vis[i+1][j]){
        int a=arr[i][j],b=arr[i+1][j];
        if(a>b)swap(a,b);
        if(!use[a][b]){
            use[a][b]=true;
            vis[i][j]=true;
            vis[i+1][j]=true;
            ret+=f(i,j+1);
            use[a][b]=false;
            vis[i][j]=false;
            vis[i+1][j]=false;
        }
    }
    if(!vis[i][j+1]){
        int a=arr[i][j],b=arr[i][j+1];
        if(a>b)swap(a,b);
        if(!use[a][b]){
            use[a][b]=true;
            vis[i][j]=true;
            vis[i][j+1]=true;
            ret+=f(i,j+1);
            use[a][b]=false;
            vis[i][j]=false;
            vis[i][j+1]=false;
        }
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    for(int i=1;i<=8;i++){
        for(int j=1;j<=7;j++){
            cin>>arr[i][j];
            arr[i][j]-='0';
        }
    }
    for(int i=0;i<=8;i++){
        vis[i][0]=vis[i][8]=true;
        vis[0][i]=vis[9][i]=true;
    }
    cout<<f(1,1)<<"\n";
    return 0;
}
