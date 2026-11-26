#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
int arr[303][303],brr[303][303];
void f(int x1,int x2,int y1,int y2){
    int a=arr[x1][y1],b=arr[x1][y2],c=arr[x2][y1],d=arr[x2][y2];
    for(int i=y1+1;i<=y2;i++)arr[x1][i-1]=arr[x1][i];
    for(int i=y2;i>y1;i--)arr[x2][i]=arr[x2][i-1];
    for(int i=x1+1;i<=x2;i++)arr[i-1][y2]=arr[i][y2];
    for(int i=x2;i>x1;i--)arr[i][y1]=arr[i-1][y1];

    arr[x1+1][y1]=a;
    arr[x1][y2-1]=b;
    arr[x2][y1+1]=c;
    arr[x2-1][y2]=d;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,M,R;cin>>N>>M>>R;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++)cin>>arr[i][j];
    }
    while(R--){
        for(int i=1;i*2<=min(N,M);i++){
            f(i,N-i+1,i,M-i+1);
        }
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++)cout<<arr[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}
