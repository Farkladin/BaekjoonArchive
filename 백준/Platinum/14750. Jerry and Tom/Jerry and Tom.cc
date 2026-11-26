// cp-algorithms.com/graph/dinic.html

#include "bits/stdc++.h"
using namespace std;
using ll=long long;

class Dinitz{
    struct Edge{
        int u,v;
        ll cap,flow;
        Edge(int u=0,int v=0,ll cap=0,ll flow=0):u(u),v(v),cap(cap),flow(flow){}
    };
    
    const ll inf=1e18;
    vector<Edge>edges;
    vector<vector<int> >G;
    int n,m=0;
    int src,sink;
    vector<int>level,ptr;
    queue<int>q;
    
public:
    Dinitz(int n,int src,int sink):n(n),src(src),sink(sink){
        G.resize(n+3);
        level.resize(n+3);
        ptr.resize(n+3);
    }
    
    void addEdge(int u,int v,ll cap){
        edges.push_back(Edge(u,v,cap));
        edges.push_back(Edge(v,u,0));
        G[u].push_back(m);
        G[v].push_back(m+1);
        m+=2;
    }
    
    bool bfs(){
        while(!q.empty()){
            int u=q.front();q.pop();
            for(int v:G[u]){
                if(edges[v].cap==edges[v].flow||level[edges[v].v]!=-1)continue;
                level[edges[v].v]=level[u]+1;
                q.push(edges[v].v);
            }
        }
        return level[sink]!=-1;
    }
    
    ll dfs(int u,ll pushed){
        if(pushed==0)return 0;
        if(u==sink)return pushed;
        for(int &cid=ptr[u];cid<(int)G[u].size();cid++){
            int cur=G[u][cid];
            int v=edges[cur].v;
            if(level[u]+1!=level[v])continue;
            ll tr=dfs(v,min(pushed,edges[cur].cap-edges[cur].flow));
            if(tr==0)continue;
            edges[cur].flow+=tr;
            edges[cur^1].flow-=tr;
            return tr;
        }
        return 0;
    }
    
    ll flow(){
        ll f=0;
        while(1){
            fill(level.begin(),level.end(),-1);
            level[src]=0;
            q.push(src);
            if(!bfs())break;
            fill(ptr.begin(),ptr.end(),0);
            while(ll pushed=dfs(src,inf))f+=pushed;
        }
        
        return f;
    }
};

using pii=pair<ll,ll>;
using ppp=pair<pii,pii>;
#define fi first
#define se second
inline int ccw(const pii &a,const pii &b,const pii &c){
    ll cp=(b.fi-a.fi)*(c.se-a.se)-(b.se-a.se)*(c.fi-a.fi);
    return cp>0?1:(cp<0?-1:0);
}

bool lsi(ppp a,ppp b){
    if(ccw(a.fi,a.se,b.fi)==0)return false;
    ll ab=ccw(a.fi,a.se,b.fi)*ccw(a.fi,a.se,b.se),ba=ccw(b.fi,b.se,a.fi)*ccw(b.fi,b.se,a.se);
    if(ab==0&&ba==0){
        if(a.fi>a.se)swap(a.fi,a.se);
        if(b.fi>b.se)swap(b.fi,b.se);
        return b.fi<=a.se&&a.fi<=b.se;
    }
    return ab<=0&&ba<=0;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,k,h,m;cin>>n>>k>>h>>m;
    
    vector<pii>arr(n);
    for(auto &p:arr)cin>>p.fi>>p.se;
    auto nexti=[&n](const int &idx)->int{
        return idx+1==n?0:idx+1;
    };
    vector<pii>hole(h);
    const int src=501,sink=502;
    Dinitz X(505,src,sink);
    
    for(int i=0;i<h;i++){
        auto &p=hole[i];
        cin>>p.fi>>p.se;
        X.addEdge(m+i+1,sink,k);
    }
    
    for(int t=1;t<=m;t++){
        pii s;cin>>s.fi>>s.se;
        X.addEdge(src,t,1);
        for(int j=0;j<h;j++){
            bool flag=false;
            for(int i=0;i<n;i++){
                flag|=lsi({arr[i],arr[nexti(i)]},{hole[j],s});
            }
            if(!flag){
                X.addEdge(t,m+j+1,1);
            }
        }
    }
    cout<<(X.flow()==m?"Possible\n":"Impossible\n");
    return 0;
}
