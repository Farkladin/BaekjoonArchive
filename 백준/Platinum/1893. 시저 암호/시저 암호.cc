#include "bits/stdc++.h"
using namespace std;
using ll=long long;
#define fi first
#define se second

void CPF(string &s,vector<int>&nxt){
    const int n=(int)s.size();
    nxt.resize(n);
    for(int i=1,j=0;i<n;i++){
        while(j>0&&s[i]!=s[j])j=nxt[j-1];
        if(s[i]==s[j])nxt[i]=++j;
    }
}

int KMP(string &T,string &P){
    vector<int>nxt;
    CPF(P,nxt);
    const int n=(int)T.size(),m=(int)P.size();
    int ans=0;
    for(int i=0,j=0;i<n;i++){
        if(j>m)j=nxt[j-1];
        while(j>0&&T[i]!=P[j])j=nxt[j-1];
        if(T[i]==P[j])j++;
        if(j==m)ans++;
    }
    return ans;
}

int main(){
    int N;cin>>N;
    while(N--){
        string A,W,S;cin>>A>>W>>S;
        vector<int>mp(256);
        const int n=(int)A.size();
        for(int i=0;i<n;i++)mp[A[i]]=i;
        
        vector<int>ans;
        for(int sh=0;sh<n;sh++){
            string cur(W.begin(),W.end());
            for(auto &c:cur){
                int idx=mp[c]+sh;
                idx=idx>=n?idx-n:idx;
                c=A[idx];
            }
            if(KMP(S,cur)==1)ans.push_back(sh);
        }
        
        switch(ans.size()){
            case 0:
                cout<<"no solution\n";
                break;
            case 1:
                cout<<"unique: "<<ans.front()<<"\n";
                break;
            default:
                cout<<"ambiguous: ";
                for(auto x:ans)cout<<x<<" ";
                cout<<"\n";
                break;
        }
    }
    return 0;
}
