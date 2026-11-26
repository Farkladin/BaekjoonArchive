#include "bits/stdc++.h"
using namespace std;

int trie[100003][30],pi[100003],SIZE=0,mp[256];
bool eos[100003];
void insert(string s){
    int p=0;
    for(auto c:s){
        int &u=trie[p][mp[c]];
        if(!u)u=++SIZE;
        p=u;
    }
    eos[p]=true;
}

void acbfs(){
    queue<int>q;
    for(int i=0;i<26;i++){
        if(trie[0][i])q.push(trie[0][i]);
    }
    
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=0;i<26;i++){
            int &v=trie[u][i];
            if(v){
                int p=pi[u];
                while(p&&!trie[p][i])p=pi[p];
                p=trie[p][i];
                pi[trie[u][i]]=p;
                if(eos[p])eos[trie[u][i]]=true;
                q.push(trie[u][i]);
            }
        }
    }
}
bool match(string s){
    int p=0;
    for(auto c:s){
        while(p&&!trie[p][mp[c]])p=pi[p];
        p=trie[p][mp[c]];
        if(eos[p])return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    for(int i='a';i<='z';i++)mp[i]=i-'a';
    
    int N;cin>>N;
    while(N--){
        string s;cin>>s;
        insert(s);
    }
    acbfs();
    int Q;cin>>Q;
    while(Q--){
        string s;cin>>s;
        cout<<(match(s)?"YES\n":"NO\n");
    }
    return 0;
}
