#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;
int anc[100003];
ll dist[100003];

int find(int x){
    if(anc[x]==x)return x;
    int root=find(anc[x]);
    dist[x]+=dist[anc[x]];
    anc[x]=root;
    return root;
}

bool solve(){
    int N,M; cin>>N>>M;
    if(N==0)return false;
    for(int i=1;i<=N;++i){
        anc[i]=i;
        dist[i]=0;
    }
    while(M--){
        char q; cin>>q;
        if(q=='!'){
            int a,b,w; cin>>a>>b>>w;
            int root_a=find(a), root_b=find(b);
            if(root_a != root_b){
                anc[root_b]=root_a;
                dist[root_b]=dist[a]+w-dist[b];
            }
        }else{
            int a,b; cin>>a>>b;
            if(find(b)!=find(a))cout<<"UNKNOWN\n";
            else cout<<dist[b]-dist[a]<<"\n";
        }
    }
    
    return true;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while(solve());
    
    return 0;
}
