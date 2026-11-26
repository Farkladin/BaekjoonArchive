#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
ll ans,arr[13],brr[13][33],cur[33];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        ans=0;
        memset(brr,0,sizeof(brr));
        for(int i=0;i<n;i++){
            int k;cin>>k;
            while(k--){
                int x;cin>>x;
                brr[i][x]++;
            }
            cin>>arr[i];
        }
        
        for(int i=1;i<=m;i++)cin>>cur[i];
        for(int i=0;i<n;i++){
            bool flag=true;
            while(1){
                for(int j=1;j<=30;j++){
                    flag&=cur[j]>=brr[i][j];
                }
                if(!flag)break;
                ans+=arr[i];
                for(int j=1;j<=30;j++){
                    cur[j]-=brr[i][j];
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
