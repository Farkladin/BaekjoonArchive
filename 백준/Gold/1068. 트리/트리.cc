#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
vector<vector<int> >G;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    G.resize(N+2);
    int root=-1;
    for(int i=0;i<N;i++){
        int par;cin>>par;
        if(par==-1)root=i;
        else G[par].push_back(i);
    }
    int x;cin>>x;
    if(x==root){
        cout<<"0\n";
        return 0;
    }
    queue<int>q;q.push(root);
    int cnt=0;
    while(!q.empty()){
        int u=q.front();q.pop();
        bool leaf=true;
        for(int v:G[u]){
            if(v!=x){
                leaf=false;
                q.push(v);
            }
        }
        cnt+=leaf;
    }
    cout<<cnt<<"\n";
    return 0;
}
