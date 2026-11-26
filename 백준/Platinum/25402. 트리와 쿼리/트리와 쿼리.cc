#include "bits/stdc++.h"
using namespace std;
using ll = long long;
vector<int>G[250003];
int pos[250003], anc[250003], mark[250003];
ll w[250003];

int find(int x){
    if(x==pos[x])return x;
    int z=x;
    while(z!=pos[z])z=pos[z];
    while(x!=pos[x]){
        int tmp=x;
        x=pos[x];
        pos[tmp]=z;
    }
    pos[x]=z;
    return z;
}
    
void uni(int x,int y){
    x=find(x);
    while(y!=pos[y]){
        int tmp=y;
        y=pos[y];
        pos[tmp]=x;
    }
    if(x!=y){
        pos[y]=x;
        w[x]+=w[y];
        w[y]=0;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int N; cin>>N;
    for(int i=1; i<N; ++i){
        int A,B; cin>>A>>B;
        G[A].push_back(B);
        G[B].push_back(A);
    }
    
    anc[1]=1;
    queue<int>q; q.push(1);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v:G[u]){
            if(!anc[v]){
                anc[v]=u;
                q.push(v);
            }
        }
    }
    
    vector<int>S; S.reserve(N+3);
    int Q; cin>>Q;
    for(int qn=1; qn<=Q; ++qn){
        int K; cin>>K;
        S.resize(K);
        for(auto &s:S){
            cin>>s;
            pos[s]=s;
            w[s]=1;
            mark[s]=qn;
        }
        
        for(auto &s:S){
            if(anc[s]!=s && mark[anc[s]]==qn){
                uni(anc[s],s);
            }
        }
        
        ll ans=0;
        for(auto &s:S){
            ll n = w[s];
            ans += (n*(n-1))>>1;
        }
        
        cout<<ans<<"\n";
    }
    
    return 0;
}
