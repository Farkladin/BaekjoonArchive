#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
vector<array<int,9> >arr,brr;
constexpr int opp[10]={
    0,6,4,5,2,3,1
};
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;cin>>n;
    arr.resize(n+3);
    brr.resize(n+3);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=6;j++){
            int x;cin>>x;
            arr[i][x]=j;
            brr[i][j]=x;
        }
    }
    int ans=0;
    for(int i=1;i<=6;i++){
        int cur=0,t=i;
        for(int j=1;j<=n;j++){
            int u=brr[j][opp[arr[j][t]]];
            for(int k=6;k>0;k--){
                if(k!=u&&k!=t){
                    cur+=k;
                    break;
                }
            }
            t=u;
        }
        ans=max(ans,cur);
    }
    cout<<ans<<"\n";
    return 0;
}
