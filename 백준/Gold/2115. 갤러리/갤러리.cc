#include "bits/stdc++.h"
using namespace std;
char arr[1003][1003];
int brr[1003][1003][4];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int M,N;cin>>M>>N;
    for(int i=1;i<=M;i++){
        for(int j=1;j<=N;j++){
            cin>>arr[i][j];
            if(arr[i][j]=='X'){
                for(int k=0;k<4;k++)brr[i][j][k]=1;
            }
        }
    }
    int cnt=0;
    for(int i=2;i<M;i++){
        for(int j=2;j<N;j++){
            if(arr[i][j]!='.')continue;
            if(arr[i][j+1]=='.'){
                if(brr[i+1][j][0]&&brr[i+1][j+1][0]){
                    brr[i+1][j][0]=brr[i+1][j+1][0]=0;
                    cnt++;
                }
                if(brr[i-1][j][1]&&brr[i-1][j+1][1]){
                    brr[i-1][j][1]=brr[i-1][j+1][1]=0;
                    cnt++;
                }
            }
            if(arr[i+1][j]=='.'){
                if(brr[i][j+1][2]&&brr[i+1][j+1][2]){
                    brr[i][j+1][2]=brr[i+1][j+1][2]=0;
                    cnt++;
                }
                if(brr[i][j-1][3]&&brr[i+1][j-1][3]){
                    brr[i][j-1][3]=brr[i+1][j-1][3]=0;
                    cnt++;
                }
            }
        }
    }
    cout<<cnt<<"\n";
    return 0;
}
