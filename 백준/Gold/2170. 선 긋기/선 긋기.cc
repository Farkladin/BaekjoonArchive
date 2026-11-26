#include "bits/stdc++.h"
using namespace std;
using ll=long long;
#define fi first
#define se second

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    vector<pair<int,int> >arr(N+N);
    for(int i=0;i<N;i++){
        int x,y;cin>>x>>y;
        arr[i*2]={x,1};
        arr[i*2+1]={y,-1};
    }
    sort(arr.begin(),arr.end());
    int cur=0,prev=-1e9,ans=0;
    for(auto p:arr){
        if(cur>0){
            ans+=p.fi-prev;
        }
        prev=p.fi;
        cur+=p.se;
    }
    cout<<ans<<"\n";
    return 0;
}
