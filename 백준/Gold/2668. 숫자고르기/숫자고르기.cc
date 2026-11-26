#include "bits/stdc++.h"
using namespace std;
using ll=long long;
#define fi first
#define se second

int G[103],vis[103];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    for(int i=1;i<=N;i++)cin>>G[i];
    vector<int>ans;
    for(int i=1;i<=N;i++){
        if(vis[i])continue;
        vis[i]=i;
        stack<int>stk({i});
        int u=G[i];
        loop:
        if(vis[u]){
            if(vis[u]==i){
                while(!stk.empty()){
                    ans.push_back(stk.top());
                    if(stk.top()==u)break;
                    stk.pop();
                }
            }
            goto out;
        }else{
            vis[u]=i;
            stk.push(u);
            u=G[u];
        }
        goto loop;
        out:
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<"\n";
    for(auto a:ans)cout<<a<<"\n";
    return 0;
}
