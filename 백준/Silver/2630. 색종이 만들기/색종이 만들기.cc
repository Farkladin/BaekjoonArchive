#include "bits/stdc++.h"
using namespace std;
int arr[200][200],cnt[2];
void f(int l,int r,int b,int t){
    bool flag=true;
    for(int i=l;i<=r;i++){
        for(int j=b;j<=t;j++){
            flag&=arr[i][j]==arr[l][b];
        }
    }
    if(flag){
        cnt[arr[l][b]]++;
        return;
    }
    int m1=(l+r)>>1,m2=(b+t)>>1;
    f(l,m1,b,m2);
    f(m1+1,r,b,m2);
    f(l,m1,m2+1,t);
    f(m1+1,r,m2+1,t);
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++)cin>>arr[i][j];
    }
    f(1,N,1,N);
    cout<<cnt[0]<<"\n"<<cnt[1]<<"\n";
    return 0;
}
