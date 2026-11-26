#include "bits/stdc++.h"
using namespace std;
using pii=pair<int,int>;

void solve(){
    int N;cin>>N;
    queue<pii>q;
    vector<string>vis(N+3);
    q.push(pii{1,1});
    vis[1]="1";
    while(!q.empty()){
        auto [x,n] = q.front(); q.pop();
        if(x==0){
            cout<<vis[0]<<"\n";
            return;
        }
        if(n==100)continue;
        
        const int nxt1=x*10%N, nxt2=(x*10+1)%N;
        if(vis[nxt1].empty()){
            vis[nxt1]=vis[x]+"0";
            q.push(pii{nxt1,n+1});
        }
        if(vis[nxt2].empty()){
            vis[nxt2]=vis[x]+"1";
            q.push(pii{nxt2,n+1});
        }
    }
    cout<<"BRAK\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;cin>>T;
    while(T--)solve();
    
    
    return 0;
}
