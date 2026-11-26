#include "bits/stdc++.h"
using namespace std;

int trie[2020000][4],pi[2020000],SIZE,mp[256],eos[2020000];
bool act[2020000];
void insert(string s){
    int p=0;
    for(auto c:s){
        int &u=trie[p][mp[c]];
        if(!u)u=++SIZE;
        p=u;
    }
    eos[p]++;
    act[p]=true;
}
    
void acbfs(){
    queue<int>q;
    for(int i=0;i<4;i++){
        if(trie[0][i])q.push(trie[0][i]);
    }
    
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=0;i<4;i++){
            int &v=trie[u][i];
            if(v){
                int p=pi[u];
                while(p&&!trie[p][i])p=pi[p];
                p=trie[p][i];
                pi[trie[u][i]]=p;
                act[trie[u][i]]|=act[p];
                q.push(trie[u][i]);
            }
        }
    }
}

int match(string s){
    int p=0,ret=0;
    for(auto c:s){
        while(p&&!trie[p][mp[c]])p=pi[p];
        p=trie[p][mp[c]];
        if(act[p])ret++;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    mp['A']=0;
    mp['G']=1;
    mp['T']=2;
    mp['C']=3;
    
    int T;cin>>T;
    while(T--){
        memset(eos,0,sizeof(eos));
        memset(act,0,sizeof(act));
        memset(pi,0,sizeof(pi));
        memset(trie,0,sizeof(trie));
        SIZE=0;
        
        int n,m;cin>>n>>m;
        string s,mark;cin>>s>>mark;
        insert(mark);
        for(int i=0;i<m;i++){
            for(int j=i+1;j<m;j++){
                string cur=mark;
                reverse(cur.begin()+i,cur.begin()+j+1);
                insert(cur);
            }
        }
        acbfs();
        cout<<match(s)<<"\n";
    }
    
    return 0;
}
