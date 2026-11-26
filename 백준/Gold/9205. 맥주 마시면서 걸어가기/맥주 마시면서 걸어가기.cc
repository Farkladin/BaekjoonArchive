#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
bool vis[105];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;cin>>t;
    while(t--){
        memset(vis,0,sizeof(vis));
        int n;cin>>n;
        const int src=n+1,sink=n+2;
        using pii=pair<int,int>;
        vector<pii>arr(105);
        cin>>arr[src].fi>>arr[src].se;
        for(int i=1;i<=n;i++)cin>>arr[i].fi>>arr[i].se;
        cin>>arr[sink].fi>>arr[sink].se;
        queue<int>q;q.push(src);
        vis[src]=true;
        while(!q.empty()){
            auto u=q.front();q.pop();
            if(u==sink)continue;
            for(int i=1;i<=n+2;i++){
                int dist=abs(arr[i].fi-arr[u].fi)+abs(arr[i].se-arr[u].se);
                if(dist<=1000){
                    if(vis[i])continue;
                    vis[i]=true;
                    q.push(i);
                }
            }
        }
        cout<<(vis[sink]?"happy\n":"sad\n");
    }
    return 0;
}
