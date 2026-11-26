#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int T,N;cin>>T>>N;
    const int n=(1<<T);
    vector<int>arr(N);
    for(int i=0;i<N;i++){
        int Z;cin>>Z;
        while(Z--){
            int x;cin>>x;
            arr[i]|=(1<<(x-1));
        }
    }
    int ans=0;
    for(int bit=0;bit<n;bit++){
        int cur=1;
        for(int x:arr){
            cur&=(x&bit)!=x;
        }
        ans+=cur;
    }
    cout<<ans<<"\n";
}
