#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
int dist[100003];
vector<vector<pair<int,int> > >G1,G2;
using pii=pair<int,int>;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,M;cin>>N>>M;
    G1.resize(N+2);
    G2.resize(N+2);
    while(M--){
        int a,b,c,d;cin>>a>>b>>c>>d;
        G1[a].push_back(pii(b,c));
        G2[a].push_back(pii(b,d));
    }
    {
        queue<pii>q;q.push({1,0});
        while(!q.empty()){
            auto [u,cur]=q.front();q.pop();
            if(u==N)dist[cur]|=1;
            for(auto [v,w]:G1[u]){
                q.push({v,cur+w});
            }
        }
    }
    {
        queue<pii>q;q.push({1,0});
        while(!q.empty()){
            auto [u,cur]=q.front();q.pop();
            if(u==N)dist[cur]|=2;
            for(auto [v,w]:G2[u]){
                q.push({v,cur+w});
            }
        }
    }
    for(int i=0;i<=100000;i++){
        if(dist[i]==3){
            cout<<i<<"\n";
            return 0;
        }
    }
    cout<<"IMPOSSIBLE\n";
    return 0;
}
