#include "bits/stdc++.h"
using namespace std;
using pii = pair<int,int>;

vector<vector<int> > G;
int dfsn[100003], dcnt=0;
vector<vector<pii> > bccs;
stack<pii> stk;
int pos[100003], id=0;

int dfs(int x,int anc){
    dfsn[x] = ++dcnt;
    int ret=dfsn[x];
    for(auto y:G[x]){
        if(y==anc)continue;
        if(dfsn[x]>dfsn[y])stk.push(pii{x,y});
        if(dfsn[y]>0)ret=min(ret,dfsn[y]);
        else{
            const int nxt=dfs(y,x);
            ret=min(nxt,ret);
            if(nxt>=dfsn[x]){
                bccs.emplace_back();
                while(stk.top() != pii{x,y}){
                    bccs.back().push_back(stk.top());
                    stk.pop();
                }
                bccs.back().push_back(stk.top());
                stk.pop();
            }
        }
    }
    
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N,M; cin>>N>>M;
    G.resize(N+3);
    while(M--){
        int x,y; cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    
    for(int i=1; i<=N; ++i){
        if(!dfsn[i])dfs(i,-1);
    }
    
    vector<pii> bridges;
    
    for(auto &bcc:bccs){
        if(bcc.size()==1){
            auto [u,v] = bcc.front();
            if(u>v) swap(u,v);
            bridges.push_back(pii{u,v});
        }
    }
    
    sort(bridges.begin(), bridges.end());
    cout<<bridges.size()<<"\n";
    for(auto [u,v]:bridges) cout<<u<<" "<<v<<"\n";
    return 0;
}
