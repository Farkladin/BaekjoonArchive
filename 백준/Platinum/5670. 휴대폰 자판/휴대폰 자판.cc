#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;

class trie{
    struct node{
        int pos;
        char c;
        node(const int p=0,const char ch='?'){
            this->pos=p;
            this->c=ch;
        }
    };

    vector<int>eos,mp,cnt;
    vector<vector<int> >M;
    int MAX,SIZE;

public:
    trie(int sz=0){
        mp.resize(256);
        MAX=sz;
        SIZE=0;
        eos.resize(MAX+3);
        cnt.resize(MAX+3);
        M.resize(MAX+3);    M.front().resize(30);
        
        for(int i='a';i<='z';i++)mp[i]=i-'a';
    }
    ~trie(){
    }
    
    void resize(int sz){
        MAX=sz;
        eos.resize(MAX+3);
        cnt.resize(MAX+3);
        M.resize(MAX+3);
    }

    void clear(){
        MAX=SIZE=0;
        M.clear();      M.resize(3);    M.front().resize(30);
        eos.clear();    eos.resize(3);
        cnt.clear();    cnt.resize(3);
    }
    
    inline int size(){
        return SIZE;
    }
    
    inline bool empty(){
        return SIZE==0;
    }
    
    void insert(string s){
        int p=0;
        for(char &c:s){
            int &tmp=M[p][mp[c]];
            if(!tmp){
                tmp=++SIZE;
                if(SIZE>MAX){
                    resize((MAX<<1)|1);
                }
                M[tmp].resize(30);
                cnt[p]++;
            }
            p=tmp;
        }
        eos[p]++;
    }
    

    bool in(string s){
        int p=0;
        for(char &c:s){
            if(!M[p][mp[c]])return false;
            p=M[p][mp[c]];
        }
        return eos[p];
    }
    
    int autocom(string s){
        int p=0,ret=1;
        for(char &c:s){
            if((p&&cnt[p]>=2)||eos[p])ret++;
            p=M[p][mp[c]];
        }
        
        return ret;
    }
};

trie T;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;
    while(cin>>N){
        vector<string>arr(N+2);
        T.clear();
        for(int i=1;i<=N;i++){
            cin>>arr[i];
            T.insert(arr[i]);
        }
        ll ans=0;
        for(int i=1;i<=N;i++){
            ans+=T.autocom(arr[i]);
        }
        ans*=1000;
        ans/=N;
        ans+=5;
        ans/=10;
        string pr=to_string(ans);
        cout<<string(pr.begin(),pr.end()-2)<<"."<<string(pr.end()-2,pr.end())<<"\n";
    }
    return 0;
}
