#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int d;cin>>d;
    string src;cin>>src;
    unordered_map<string,int>vis,valid;
    vis[src]=1;
    while(d--){
        string s;cin>>s;
        valid[s]=1;
    }
    queue<string>q;q.push(src);
    while(!q.empty()){
        auto u=q.front();q.pop();
        const int n=(int)u.size();
        for(char c='a';c<='z';c++){
            for(int i=0;i<=n;i++){
                string nxt=string(u.begin(),u.begin()+i)+c+string(u.begin()+i,u.end());
                if(valid[nxt]&&!vis[nxt]){
                    vis[nxt]=1;
                    q.push(nxt);
                }
            }
        }
    }
    string ans;
    for(auto it=vis.begin();it!=vis.end();it++){
        if(ans.size()<it->fi.size()){
            ans=it->fi;
        }
    }
    cout<<ans<<"\n";
    
    return 0;
}
