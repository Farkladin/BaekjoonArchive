#include "bits/stdc++.h"
using namespace std;
int arr[3000][3000],cnt[3];
string ans;
void f(int l,int r,int b,int t,int k){
    k/=3;
    bool flag=true;
    for(int i=l;i<=r;i++){
        for(int j=b;j<=t;j++){
            flag&=arr[i][j]==arr[l][b];
        }
    }
    if(flag){
        cnt[arr[l][b]+1]++;
        return;
    }
    f(l,l+k-1,b,b+k-1,k);f(l+k,l+k*2-1,b,b+k-1,k);f(l+k*2,l+k*3-1,b,b+k-1,k);
    f(l,l+k-1,b+k,b+k*2-1,k);f(l+k,l+k*2-1,b+k,b+k*2-1,k);f(l+k*2,l+k*3-1,b+k,b+k*2-1,k);
    f(l,l+k-1,b+k*2,b+k*3-1,k);f(l+k,l+k*2-1,b+k*2,b+k*3-1,k);f(l+k*2,l+k*3-1,b+k*2,b+k*3-1,k);
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++)cin>>arr[i][j];
    }
    f(1,N,1,N,N);
    cout<<cnt[0]<<"\n"<<cnt[1]<<"\n"<<cnt[2]<<"\n";
    return 0;
}
