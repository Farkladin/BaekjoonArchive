#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;

vector<vector<int> >G;
int vis[2003],cnt;
bool flag=false;
void f(int x){
    if(flag)return;
    for(int y:G[x]){
        if(!vis[y]){
            cnt++;
            if(cnt>=5){
                flag=true;
                return;
            }
            vis[y]=true;
            f(y);
            vis[y]=false;
            cnt--;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,M;cin>>N>>M;
    G.resize(N+2);
    while(M--){
        int a,b;cin>>a>>b;
        G[a+1].push_back(b+1);
        G[b+1].push_back(a+1);
    }
    for(int i=1;i<=N;i++){
        flag=false;
        f(i);
        if(flag)goto found;
    }
    cout<<"0\n";
    return 0;
    
    found:
    cout<<"1\n";
    return 0;
}
