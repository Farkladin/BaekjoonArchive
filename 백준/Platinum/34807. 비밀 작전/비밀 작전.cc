#include "bits/stdc++.h"
using namespace std;
using ll=long long;
class disjoint_set{
    vector<int>pos;
    vector<ll>w,mn;
    int i,z,tmp;
public:
    disjoint_set(int n,const vector<ll>&init):w(vector<ll>(n+1,1)),mn(init){
        pos.resize(n+1);
        for(i=1;i<=n;i++)pos[i]=i;
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
            mn[x]=std::min(mn[x],mn[y]);
            mn[y]=mn[x];
            w[y]=0;
        }
    }
    
    ll cnt(int x){
        x=find(x);
        return w[x];
    }
    
    ll min(int x){
        x=find(x);
        return mn[x];
    }
};
 
#define fi first
#define se second
vector<vector<int> >G;
vector<ll>a;
vector<pair<ll,int> >vp;
vector<int>q;
int N,M,Q;ll X;
 
bool g(int k){
    vector<ll>init(a);
    vector<bool>vis(N+2);
    for(int i=1;i<=k;i++){
        init[q[i]]=0;
    }
    
    disjoint_set ds(N,init);
    for(const auto &[w,v]:vp){
        if(init[v]==0)continue;
        vis[v]=true;
        for(const auto &u:G[v]){
            if(vis[u])ds.uni(v,u);
        }
        ll div=ds.min(v),cnt=ds.cnt(v);
        if(div==0)continue;
        if(X%div==0 && X/div<=cnt)return true;
    }
    return false;
}
 
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin>>N>>M>>X;
    a.resize(N+2);
    vp.resize(N);
    G.resize(N+2);
    for(int i=1;i<=N;i++){
        cin>>a[i];
        vp[i-1]={a[i],i};
    }
    sort(vp.begin(),vp.end(),greater<pair<ll,int> >());
    while(M--){
        int u,v;cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    cin>>Q;
    q.resize(Q+2);
    for(int i=1;i<=Q;i++)cin>>q[i];
    
    int le=1,ri=Q+1,mid;
    while(le<ri){
        mid=(le+ri)>>1;
        if(g(mid)){
            le=mid+1;
        }else{
            ri=mid;
        }
    }
    for(int i=1;i<le;i++)cout<<"1\n";
    for(int i=le;i<=Q;i++)cout<<"0\n";
    return 0;
}
