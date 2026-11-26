#include "bits/stdc++.h"
using namespace std;
char arr[55][55];
const char brr[10][10]={
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW"
};
int f(int x0,int y0){
    int cnt1=0,cnt2=0;
    for(int i=x0;i<x0+8;i++){
        for(int j=y0;j<y0+8;j++){
            if(brr[i-x0][j-y0]!=arr[i][j])cnt1++;
            if(brr[i-x0][j-y0]==arr[i][j])cnt2++;
        }
    }
    return min(cnt1,cnt2);
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,M;cin>>N>>M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++)cin>>arr[i][j];
    }
    
    int ans=1e9;
    for(int i=1;i+7<=N;i++){
        for(int j=1;j+7<=M;j++){
            ans=min(ans,f(i,j));
        }
    }
    cout<<ans<<"\n";
    return 0;
}
