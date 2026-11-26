#include "bits/stdc++.h"
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    unordered_map<string,bool>vis;
    vis["ChongChong"]=true;
    int cnt=1;
    while(N--){
        string a,b;cin>>a>>b;
        if(vis[a]&&!vis[b]){
            vis[b]=true;
            cnt++;
        }else if(!vis[a]&&vis[b]){
            vis[a]=true;
            cnt++;
        }
    }
    
    cout<<cnt<<"\n";
    return 0;
}
