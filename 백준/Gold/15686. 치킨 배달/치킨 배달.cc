#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
using ull=unsigned long long;
vector<pair<int,int> >arr,brr;
inline int dist(const pair<int,int>&a,const pair<int,int>&b){
    return abs(a.fi-b.fi)+abs(a.se-b.se);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,M;cin>>N>>M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            int x;cin>>x;
            if(x==1){
                arr.push_back({i,j});
            }else if(x==2){
                brr.push_back({i,j});
            }
        }
    }
    
    int n=(int)brr.size();
    int ans=1e9;
    for(int bit=1;bit<(1<<n);bit++){
        if(__builtin_popcount(bit)!=M)continue;
        int sum=0;
        for(auto &house:arr){
            int cur=1e9;
            for(int j=0;j<n;j++){
                if(bit&(1<<j))cur=min(cur,dist(house,brr[j]));
            }
            sum+=cur;
        }
        ans=min(ans,sum);
    }
    cout<<ans<<"\n";
    return 0;
}
