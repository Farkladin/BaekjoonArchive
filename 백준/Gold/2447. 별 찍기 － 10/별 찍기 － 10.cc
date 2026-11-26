#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
char ans[6561][6561];
void f(int x1,int x2,int y1,int y2,int k){
    if(x1==x2){
        ans[x1][y1]='*';
        return;
    }
    int cnt=0;
    for(int i=x1;i<=x2;i+=k){
        for(int j=y1;j<=y2;j+=k){
            cnt++;
            if(cnt==5){
                for(int x=i;x<i+k;x++){
                    for(int y=j;y<j+k;y++){
                        ans[x][y]=' ';
                    }
                }
            }else f(i,i+k-1,j,j+k-1,k/3);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    f(1,N,1,N,N/3);
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++)cout<<ans[i][j];
        cout<<"\n";
    }
    return 0;
}
