#include "bits/stdc++.h"
using namespace std;

int dist[1003][23];
const array<int,4>dx={1,5,10,50};
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    queue<pair<int,int> >q;
    q.push({1,1});
    q.push({5,1});
    q.push({10,1});
    q.push({50,1});
    dist[1][1]=dist[5][1]=dist[10][1]=dist[50][1]=1;
    while(!q.empty()){
        auto [u,n]=q.front();q.pop();
        if(n>=N)continue;
        for(auto d:dx){
            if(!dist[u+d][n+1]){
                dist[u+d][n+1]=1;
                q.push({u+d,n+1});
            }
        }
    }
    int ans=0;
    for(int i=1;i<=1000;i++)ans+= dist[i][N];
    cout<<ans<<"\n";
    return 0;
}
