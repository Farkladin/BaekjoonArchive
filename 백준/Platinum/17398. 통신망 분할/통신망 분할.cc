#include "bits/stdc++.h"
using namespace std;
using ll=long long;
class disjoint_set{
public:
    vector<int>pos;
    vector<ll>w;
    int i,z,tmp;

    disjoint_set(int n=0){
        pos.resize(n+1);
        w=vector<ll>(n+1,1);
        for(i=1;i<=n;++i)pos[i]=i;
    }
    ~disjoint_set(){
        pos.clear();
        w.clear();
    }
    
    int find(int x){
        if(x==pos[x])return x;
        z=x;
        while(z!=pos[z])z=pos[z];
        while(x!=pos[x]){
            tmp=x;
            x=pos[x];
            pos[tmp]=z;
        }
        pos[x]=z;
        return z;
    }
    
    void uni(int x,int y){
        x=find(x);
        while(y!=pos[y]){
            tmp=y;
            y=pos[y];
            pos[tmp]=x;
        }
        if(x!=y){
            pos[y]=x;
            w[x]+=w[y];
            w[y]=0;
        }
    }
};

pair<int,int> edges[100003];
bool used[100003];
int query[100003];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N,M,Q;cin>>N>>M>>Q;
    disjoint_set ds(N);
    
    for(int i=1;i<=M;++i)cin>>edges[i].first>>edges[i].second;
    for(int i=1;i<=Q;++i){
        cin>>query[i];
        used[query[i]]=true;
    }
    for(int i=1;i<=M;++i){
        auto [a,b]=edges[i];
        if(!used[i]){
            ds.uni(a,b);
        }
    }
    
    ll ans=0;
    for(int i=Q;i>0;--i){
        auto [a,b]=edges[query[i]];
        a=ds.find(a);
        b=ds.find(b);
        if(a!=b)ans+=ds.w[a]*ds.w[b];
        ds.uni(a,b);
    }
    
    cout<<ans<<"\n";
    
    return 0;
}
