#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;
int dist[100003];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,K;cin>>N>>K;
    fill(dist,dist+100001,1e9);
    dist[N]=0;
    deque<int>dq;dq.push_back(N);
    while(!dq.empty()){
        auto u=dq.front();dq.pop_front();
        if(u*2<=100000&&dist[u*2]>dist[u]){
            dq.push_front(u*2);
            dist[u*2]=dist[u];
        }
        if(u+1<=100000&&dist[u+1]>dist[u]+1){
            dq.push_back(u+1);
            dist[u+1]=dist[u]+1;
        }
        if(u-1>=0&&dist[u-1]>dist[u]+1){
            dq.push_back(u-1);
            dist[u-1]=dist[u]+1;
        }
    }
    cout<<dist[K]<<"\n";
    return 0;
}
