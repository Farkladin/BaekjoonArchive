#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;

vector<vector<int> >G;
int dp[100003];
bool vis[100003];
int f(int u){
    int &ret=dp[u];
    ret=1;
    for(int v:G[u]){
        if(!vis[v]){
            vis[v]=true;
            ret+=f(v);
        }
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,R,Q;cin>>N>>R>>Q;
    G.resize(N+3);
    for(int i=1;i<N;i++){
        int U,V;cin>>U>>V;
        G[U].push_back(V);
        G[V].push_back(U);
    }
    vis[R]=true;
    f(R);
    while(Q--){
        int U;cin>>U;
        cout<<dp[U]<<"\n";
    }
    
    return 0;
}
