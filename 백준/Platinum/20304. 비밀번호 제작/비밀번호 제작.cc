#include "bits/stdc++.h"
using namespace std;

int dist[1'000'003];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N,M; cin>>N>>M;
    queue<int>q;
    while(M--){
        int p; cin>>p;
        dist[p]=1;
        q.push(p);
    }
    
    int ans=0;
    while(!q.empty()){
        int u=q.front(); q.pop();
        for(int t=1; t<=N; t<<=1){
            if((u^t)<=N && !dist[u^t]){
                q.push(u^t);
                dist[u^t]=dist[u]+1;
                ans=max(ans,dist[u]);
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}
