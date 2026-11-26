#include "bits/stdc++.h"
using namespace std;

pair<int,int>arr[100003];
int cnt[33];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N,K,D; cin>>N>>K>>D;
    for(int i=1; i<=N; ++i){
        auto &[d,bit]=arr[i];
        int M; cin>>M>>d;
        while(M--){
            int x; cin>>x;
            bit|=1<<x;
        }
    }
    
    sort(arr+1,arr+1+N);
    
    long long ans=0;
    for(int le=1,ri=1; ri<=N; ++ri){
        for(int i=1;i<=30;++i){
            if((1<<i)&arr[ri].second)++cnt[i];
        }
        
        while(arr[ri].first-arr[le].first>D){
            for(int i=1;i<=30;++i){
                if((1<<i)&arr[le].second)--cnt[i];
            }
            ++le;
        }
        
        long long a=0, b=0;
        for(int i=1;i<=30;++i){
            if(cnt[i]==ri-le+1)++b;
            if(cnt[i])++a;
        }
        
        ans=max(ans,(a-b)*(ri-le+1));
    }
    
    cout<<ans<<"\n";
    
    return 0;
}
