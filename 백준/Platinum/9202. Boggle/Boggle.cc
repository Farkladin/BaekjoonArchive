#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;

constexpr int dx[8]={-1,1,0,0,-1,1,-1,1},dy[8]={0,0,-1,1,-1,-1,1,1};
int trie[2400003][27],SIZE=0,eos[2400003],mp[256];
void insert(string s){
    int p=0;
    for(auto c:s){
        int &u=trie[p][mp[c]];
        if(!u){
            u=++SIZE;
        }
        p=u;
    }
    eos[p]++;
}

char arr[6][6];
set<string>found;
bool vis[6][6];
constexpr int sb[10]={-1,0,0,1,1,2,3,5,11};
void f(int i,int j,int u,string s){
    if(eos[u]){
        found.insert(s);
    }
    for(int k=0;k<8;k++){
        int x=i+dx[k],y=j+dy[k];
        if(1<=x&&x<=4&&1<=y&&y<=4&&!vis[x][y]&&trie[u][mp[arr[x][y]]]){
            vis[x][y]=true;
            f(x,y,trie[u][mp[arr[x][y]]],s+arr[x][y]);
            vis[x][y]=false;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    for(int i='A';i<='Z';i++)mp[i]=i-'A';
    int w;cin>>w;
    while(w--){
        string s;cin>>s;
        insert(s);
    }
    int b;cin>>b;
    while(b--){
        for(int i=1;i<=4;i++){
            for(int j=1;j<=4;j++)cin>>arr[i][j];
        }
        found.clear();
        for(int i=1;i<=4;i++){
            for(int j=1;j<=4;j++){
                if(trie[0][mp[arr[i][j]]]){
                    vis[i][j]=true;
                    f(i,j,trie[0][mp[arr[i][j]]],string(1,arr[i][j]));
                    vis[i][j]=false;
                }
            }
        }
        string ans;
        int score=0;
        for(auto &s:found){
            if(ans.size()<s.size()){
                ans=s;
            }
            score+=sb[s.size()];
        }
        
        cout<<score<<" "<<ans<<" "<<found.size()<<"\n";
    }
    
    return 0;
}
