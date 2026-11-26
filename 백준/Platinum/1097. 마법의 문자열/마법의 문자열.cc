#include "bits/stdc++.h"
using namespace std;
using ll=long long;
vector<int>cpf(string &s){
    const int n=(int)s.size();
    vector<int>nxt(n);
    for(int i=1,j=0;i<n;i++){
        while(j>0&&s[i]!=s[j])j=nxt[j-1];
        if(s[i]==s[j])nxt[i]=++j;
    }
    return nxt;
}

vector<int>kmp(string &T,string &P){
    vector<int>nxt=cpf(P),ans;
    const int n=(int)T.size(),m=(int)P.size();
    for(int i=0,j=0;i<n;i++){
        if(j>m)j=nxt[j-1];
        while(j>0&&T[i]!=P[j])j=nxt[j-1];
        if(T[i]==P[j])j++;
        if(j==m)ans.push_back(i-m+2);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    vector<int>pt(N);
    vector<string>vs(N);
    for(int i=0;i<N;i++){
        cin>>vs[i];
        pt[i]=i;
    }
    int K;cin>>K;
    int ans=0,t=1;
    for(int i=1;i<=N;i++)t*=i;
    for(int i=0;i<t;i++){
        string cur,T;
        for(auto x:pt){
            T+=vs[x];
            cur+=vs[x];
        }
        T+=T;T.pop_back();
        if((int)kmp(T,cur).size()==K)ans++;
        next_permutation(pt.begin(),pt.end());
    }
    cout<<ans<<"\n";
    return 0;
}
