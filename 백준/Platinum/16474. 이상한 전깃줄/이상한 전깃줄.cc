#include "bits/stdc++.h"
using namespace std;

vector<int>arr[2003];
int lpos[2003],rpos[2003];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,M; cin>>N>>M;
    for(int i=1; i<=N; ++i){
        int x;cin>>x;
        lpos[x]=i;
    }
    for(int j=1;j<=M;++j){
        int x;cin>>x;
        rpos[x]=j;
    }
    
    int K; cin>>K;
    for(int i=1; i<=K; ++i){
        int u,v; cin>>u>>v;
        arr[rpos[v]].push_back(lpos[u]);
    }
    
    vector<int>vec;
    for(int i=1; i<=M; ++i){
        sort(arr[i].begin(),arr[i].end(),greater<int>());
        vec.insert(vec.end(),arr[i].begin(),arr[i].end());
    }
    
    vector<int>lis;
    for(auto x:vec){
        if(lis.empty() || lis.back()<x){
            lis.push_back(x);
        }else{
            int pos = int(lower_bound(lis.begin(),lis.end(),x)-lis.begin());
            lis[pos]=x;
        }
    }
    
    cout<<K-lis.size()<<"\n";
    return 0;
}
