#include "bits/stdc++.h"
using namespace std;

vector<vector<int> > G;
vector<int> pU, pV, dist;
bool bfs(const int &n, const int &m){
    queue<int> q;
    for(int u=1; u<=n; ++u){
        if(pU[u]==-1){
            dist[u]=0;
            q.push(u);
        }else{
            dist[u]=1e9;
        }
    }
    
    int found = false;
    while(!q.empty()){
        auto u = q.front(); q.pop();
        if(dist[u]>=1e9)continue;
        for(auto v:G[u]){
            if(pV[v]==-1){
                found=true;
            }else if(dist[pV[v]]==1e9){
                dist[pV[v]]=dist[u]+1;
                q.push(pV[v]);
            }
        }
    }
    
    return found;
}

bool dfs(int u){
    for(auto v:G[u]){
        if(pV[v]==-1 || (dist[pV[v]]==dist[u]+1 && dfs(pV[v]))){
            pV[v]=u;
            pU[u]=v;
            return true;
        }
    }
    
    dist[u]=1e9;
    return false;
}

int HopcroftKarp(const int &n, const int &m){
    pU.resize(n+2);
    pV.resize(m+2);
    dist.resize(n+2);
    fill(pU.begin(), pU.end(), -1);
    fill(pV.begin(), pV.end(), -1);
    
    int ret=0;
    while(bfs(n,m)){
        for(int u=1; u<=n; ++u){
            if(pU[u]==-1 && dfs(u)){
                ++ret;
            }
        }
    }
    
    return ret;
}

int8_t sieve[2003];
vector<pair<int,int> >edges;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    sieve[1]=1;
    for(int i=2; i*i<=2000; ++i){
        if(sieve[i])continue;
        for(int j=i+i; j<=2000; j+=i){
            sieve[j]=1;
        }
    }
    
    int N; cin>>N;
    vector<int>even,odd,arr(N);
    even.reserve(N);
    odd.reserve(N);
    bool flag=false;
    for(int i=1; i<=N; ++i){
        int a; cin>>a;
        if(a&1 && i==1)flag=true;
        if(a&1)odd.push_back(a);
        else even.push_back(a);
    }
    
    const int n=(int)odd.size(), m=(int)even.size();
    edges.reserve(n*m+5);
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(!sieve[odd[i]+even[j]]){
                edges.emplace_back(i+1,j+1);
            }
        }
    }
    
    if(flag){
        vector<int>ans;ans.reserve(N);
        for(int i=0; i<m; ++i){
            if(!sieve[odd[0]+even[i]]){
                G.clear();
                G.resize(N+3);
                for(auto [u,v]:edges){
                    if(u!=1 && v!=i+1) G[u].push_back(v);
                }
                
                if(HopcroftKarp(n,m)+1==(N>>1)){
                    ans.push_back(even[i]);
                }
            }
        }
        
        sort(ans.begin(), ans.end());
        for(auto a:ans)cout<<a<<" ";
        if(ans.empty())cout<<-1;
        cout<<"\n";
    }else{
        vector<int>ans;ans.reserve(N);
        
        for(int i=0; i<n; ++i){
            if(!sieve[even[0]+odd[i]]){
                G.clear();
                G.resize(N+3);
                for(auto [u,v]:edges){
                    if(v!=1 && u!=i+1) G[u].push_back(v);
                }
                
                if(HopcroftKarp(n,m)+1==(N>>1)){
                    ans.push_back(odd[i]);
                }
            }
        }
        
        sort(ans.begin(), ans.end());
        for(auto a:ans)cout<<a<<" ";
        if(ans.empty())cout<<-1;
        cout<<"\n";
    }
    return 0;
}
