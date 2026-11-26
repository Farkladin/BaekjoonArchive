#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int cnt[1000003],arr[100003];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    for(int i=1;i<=N;i++){
        int x;cin>>x;
        arr[i]=x;
        cnt[x]++;
    }
    for(int i=1;i<=N;i++){
        int ans=0;
        for(int j=1;j*j<=arr[i];j++){
            int t=arr[i]/j;
            if(t*j==arr[i]){
                ans+=cnt[j];
                if(t!=j)ans+=cnt[t];
            }
        }
        cout<<ans-1<<"\n";
    }
    return 0;
}
