#include "bits/stdc++.h"
using namespace std;
int N,K;
int arr[103],brr[103][103],crr[103][103];
bool f(){
    memset(brr,0,sizeof(brr));
    
    vector<int>idcs;
    int mn=1e9,mx=0;
    for(int i=1;i<=N;i++){
        brr[1][i]=arr[i];
        mx=max(mx,arr[i]);
        if(mn>arr[i]){
            mn=arr[i];
            idcs.clear();
        }
        if(mn==arr[i])idcs.push_back(i);
    }
    for(auto idx:idcs)brr[1][idx]++;
    if(mx-mn<=K)return false;
    
    int a=1,b=2,p=3;
    brr[2][2]=brr[1][1];
    brr[1][1]=0;
    while(p+b-1<=N){
        for(int i=p,ii=1;i<p+b;++i,++ii){
            for(int j=2,jj=p-1;j<2+a;++j,--jj){
                brr[j][i]=brr[ii][jj];
                brr[ii][jj]=0;
            }
        }
        p+=b;
        int tmp=a+1;
        a=b;
        b=tmp;
    }
    
    memset(crr,0,sizeof(crr));
    for(int i=1;i<=N;++i){
        for(int j=1;j<=N;++j){
            crr[i][j]+=brr[i][j];
            int x,y;
            
            x=i-1;y=j;
            if(brr[i][j] && brr[x][y]){
                int diff=(brr[i][j]-brr[x][y])/5;
                crr[i][j]-=diff;
                crr[x][y]+=diff;
            }
            
            x=i;y=j-1;
            if(brr[i][j] && brr[x][y]){
                int diff=(brr[i][j]-brr[x][y])/5;
                crr[i][j]-=diff;
                crr[x][y]+=diff;
            }
        }
    }
    
    int iter;
    
    iter=0;
    for(int j=1;j<=N;j++){
        for(int i=1;i<=N;i++){
            if(crr[i][j])arr[++iter]=crr[i][j];
        }
    }
    
    memset(brr,0,sizeof(brr));
    for(int i=1;i<=N;i++)brr[1][i]=arr[i];
    for(int i=N,j=1;j<=N/2;j++,i--){
        brr[2][i]=brr[1][j];
        brr[1][j]=0;
    }
    
    for(int i=N,j=N/2+1;j<=N/4*3;j++,i--){
        brr[4][i]=brr[1][j];
        brr[3][i]=brr[2][j];
        brr[1][j]=brr[2][j]=0;
    }
    
    memset(crr,0,sizeof(crr));
    for(int i=1;i<=N;++i){
        for(int j=1;j<=N;++j){
            crr[i][j]+=brr[i][j];
            int x,y;
            
            x=i-1;y=j;
            if(brr[i][j] && brr[x][y]){
                int diff=(brr[i][j]-brr[x][y])/5;
                crr[i][j]-=diff;
                crr[x][y]+=diff;
            }
            
            x=i;y=j-1;
            if(brr[i][j] && brr[x][y]){
                int diff=(brr[i][j]-brr[x][y])/5;
                crr[i][j]-=diff;
                crr[x][y]+=diff;
            }
        }
    }
    
    iter=0;
    for(int j=1;j<=N;j++){
        for(int i=1;i<=N;i++){
            if(crr[i][j])arr[++iter]=crr[i][j];
        }
    }
    
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin>>N>>K;
    for(int i=1;i<=N;i++)cin>>arr[i];
    int ans=0;
    while(f())ans++;
    cout<<ans<<"\n";
    return 0;
}
