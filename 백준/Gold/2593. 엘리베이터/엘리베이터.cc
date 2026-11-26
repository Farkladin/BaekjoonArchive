#include "bits/stdc++.h"
using namespace std;
vector<int> G[200003];
int dist[200003], anc[200003];
pair<int,int> arr[103];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int N,M; cin>>N>>M;
    for(int i=1; i<=M; ++i){
        int X,Y; cin>>X>>Y;
        for(int j=X; j<=N; j+=Y){
            G[N+i].push_back(j);
            G[j].push_back(N+i);
        }
    }
    
    int A,B; cin>>A>>B;
    fill(dist,dist+N+M+3,1e9);
    deque<int> dq{A};
    dist[A]=0;
    while(!dq.empty()){
        auto u=dq.front(); dq.pop_front();
        for(auto v:G[u]){
            if(dist[v] > dist[u]+1 && v>N){
                dist[v]=dist[u]+1;
                anc[v]=u;
                dq.push_back(v);
            }else if(dist[v] > dist[u] && v<=N){
                dist[v]=dist[u];
                anc[v]=u;
                dq.push_front(v);
            }
        }
    }
    
    if(dist[B]==1e9){
        cout<<"-1\n";
        return 0;
    }
    
    cout<<dist[B]<<"\n";
    stack<int>stk;
    while(anc[B]){
        if(anc[B]>N){
            stk.push(anc[B]-N);
        }
        B=anc[B];
    }
    while(!stk.empty()){
        cout<<stk.top()<<"\n"; stk.pop();
    }
    
    return 0;
}
