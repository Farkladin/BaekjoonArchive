#include "bits/stdc++.h"
#pragma GCC optimize("O3", "unroll-loops")
using namespace std;

int trie[500003][30],pi[500003],SIZE=0,mp[256],mx[500003];
void insert(string s){
    int p=0;
    for(auto c:s){
        int &u=trie[p][mp[c]];
        if(!u)u=++SIZE;
        p=u;
    }
    mx[p]=max(mx[p],(int)s.size());
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
                pi[v]=p;
                mx[v]=max(mx[v],mx[p]);
                q.push(v);
            }
        }
    }
}

int arr[300003];
void match(string s){
    int p=0,it=0;
    for(auto c:s){
        it++;
        while(p&&!trie[p][mp[c]])p=pi[p];
        p=trie[p][mp[c]];
        arr[it+1]--;
        arr[max(it+1-mx[p],1)]++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    for(int i='a';i<='z';i++)mp[i]=i-'a';
    
    int N;cin>>N;
    string s;cin>>s;
    int M;cin>>M;
    int cnt=0;
    while(M--){
        cnt++;
        string t;cin>>t;
        insert(t);
        if(cnt==100||M==0){
            cnt=0;
            acbfs();
            match(s);
            SIZE=0;
            memset(trie,0,sizeof(trie));
            memset(pi,0,sizeof(pi));
            memset(mx,0,sizeof(mx));
        }
    }
    int ans=0;
    for(int i=1;i<=N;i++){
        arr[i]+=arr[i-1];
        if(arr[i]==0)ans++;
    }
    cout<<ans<<"\n";
    return 0;
}
