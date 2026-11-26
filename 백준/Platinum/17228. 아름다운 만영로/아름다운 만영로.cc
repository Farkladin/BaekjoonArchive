#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
vector<vector<pair<int,char> > >G;

vector<int>cpf(const string &s){
    const int n=(int)s.size();
    vector<int>nxt(n);
    for(int i=1,j=0;i<n;i++){
        while(j>0&&s[i]!=s[j])j=nxt[j-1];
        if(s[i]==s[j])nxt[i]=++j;
    }
    return nxt;
}

std::vector<int>computeNext(const std::string &pattern){
    const int m=(int)pattern.size()-1;
    std::vector<int>next(m+1);
    int j=1,t=0; next[1]=0;
    while(j<m){
        while(t>0 && pattern[j]!=pattern[t])t=next[t];
        t++;j++;
        if(pattern[j]==pattern[t])next[j]=next[t];
        else next[j]=t;
    }
    return next;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    G.resize(N+2);
    for(int i=1;i<N;i++){
        int u,v;char c;cin>>u>>v>>c;
        G[u].push_back({v,c});
    }
    
    string s;cin>>s;
    s="!"+s+"@";
    const int m=(int)s.size()-2;
    auto nxt=computeNext(s);
    
    int ans=0;
    queue<pair<int,int> >q;q.push({1,1});
    while(!q.empty()){
        auto [u,j]=q.front();q.pop();
        for(auto [v,c]:G[u]){
            int t=j;
            while(t>1&&c!=s[t])t=nxt[t];
            if(t==0){
                q.push({v,1});
                continue;
            }
            if(c==s[t])t++;
            if(t>m){
                ans++;
                t=nxt[t];
            }
            q.push({v,t});
        }
    }
    cout<<ans<<"\n";
    return 0;
}
