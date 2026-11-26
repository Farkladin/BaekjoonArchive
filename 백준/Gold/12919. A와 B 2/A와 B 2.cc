#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    string S,T;cin>>S>>T;
    map<string,bool>mp;
    mp[T]=true;
    queue<string>q;q.push(T);
    while(!q.empty()){
        auto u=q.front();q.pop();
        if(u.size()<=S.size())continue;
        if(u.back()=='A'){
            string nxt=u;nxt.pop_back();
            if(!mp[nxt]){
                mp[nxt]=true;
                q.push(nxt);
            }
        }
        if(u.front()=='B'){
            string nxt(u.rbegin(),u.rend()-1);
            if(!mp[nxt]){
                mp[nxt]=true;
                q.push(nxt);
            }
        }
    }
    cout<<mp[S]<<"\n";
    return 0;
}
