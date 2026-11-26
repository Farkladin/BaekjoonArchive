#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using lf=double;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;
using ppp=pair<pii,pii>;
char arr[4][8];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    for(int i=0;i<4;i++){
        for(int j=0;j<8;j++)cin>>arr[i][j];
    }
    
    int K;cin>>K;
    while(K--){
        int a,b;cin>>a>>b;
        a--;
        queue<pair<int,int> >q;q.push({a,b});
        array<bool,5>vis={false};
        vis[a]=true;
        while(!q.empty()){
            auto [u,d]=q.front();q.pop();
            if(u>0&&arr[u][6]!=arr[u-1][2]&&!vis[u-1]){
                vis[u-1]=true;
                q.push({u-1,-1*d});
            }
            if(u<3&&arr[u+1][6]!=arr[u][2]&&!vis[u+1]){
                vis[u+1]=true;
                q.push({u+1,-1*d});
            }
            array<int,8>tmp;
            for(int i=0;i<8;i++)tmp[i]=arr[u][(i-d+8)%8];
            for(int i=0;i<8;i++)arr[u][i]=tmp[i];
        }
    }
    int ans=0;
    for(int i=0;i<4;i++){
        ans+=(arr[i][0]-'0')*(1<<i);
    }
    cout<<ans<<"\n";
    
    return 0;
}

