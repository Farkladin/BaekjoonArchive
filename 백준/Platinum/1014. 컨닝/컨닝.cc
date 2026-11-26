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

char arr[88][88];
int pos[88][88];
const int dx[6] = {-1,-1,0,0,1,1}, dy[6] = {1,-1,1,-1,1,-1};
int solve(){
    int N,M; cin>>N>>M;
    G.clear();
    memset(arr,'!',sizeof(arr));
    int odd=0, even=0, ans=0;
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=M; ++j){
            cin>>arr[i][j];
            if(arr[i][j]=='.')++ans;
            if(j&1)pos[i][j]=++odd;
            else pos[i][j]=++even;
        }
    }
    G.resize(odd+even+3);
    
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=M; ++j){
            if((j&1) && arr[i][j]=='.'){
                const int u = pos[i][j];
                for(int k=0; k<6; ++k){
                    int x=i+dx[k],y=j+dy[k];
                    const int v = pos[x][y];
                    if(arr[x][y]=='.')G[u].push_back(v);
                }
            }
        }
    }
    
    return ans-HopcroftKarp(odd, even);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int C; cin>>C;
    for(int tc=1; tc<=C; ++tc){
        cout<<solve()<<"\n";
    }
    
    return 0;
}
