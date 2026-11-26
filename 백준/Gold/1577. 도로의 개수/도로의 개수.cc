#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
ll dp[103][103];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,M,K;cin>>N>>M>>K;
    vector<array<int,4> >va(K);
    for(auto &ar:va){
        cin>>ar[0]>>ar[1]>>ar[2]>>ar[3];
        if(ar[0]>ar[2]||(ar[0]==ar[2]&&ar[1]>ar[3])){
            swap(ar[0],ar[2]);
            swap(ar[1],ar[3]);
        }
    }
    dp[0][0]=1;
    for(int i=0;i<=N;i++){
        for(int j=0;j<=M;j++){
            bool flag=true;
            for(auto &ar:va){
                if(ar[0]==i&&ar[1]==j&&ar[2]==i+1&&ar[3]==j){
                    flag=false;
                }
            }
            if(flag)dp[i+1][j]+=dp[i][j];
            flag=true;
            for(auto &ar:va){
                if(ar[0]==i&&ar[1]==j&&ar[2]==i&&ar[3]==j+1){
                    flag=false;
                }
            }
            if(flag)dp[i][j+1]+=dp[i][j];
        }
    }
    cout<<dp[N][M]<<"\n";
    return 0;
}
