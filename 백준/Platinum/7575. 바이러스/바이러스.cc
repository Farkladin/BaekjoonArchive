#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
using ppp=pair<pii,pii>;

vector<int>cpf(vector<int> &s){
    const int n=(int)s.size();
    vector<int>nxt(n);
    for(int i=1,j=0;i<n;i++){
        while(j>0&&s[i]!=s[j])j=nxt[j-1];
        if(s[i]==s[j])nxt[i]=++j;
    }
    return nxt;
}

vector<int>kmp(vector<int> &T,vector<int> &P){
    vector<int>nxt=cpf(P),ans;
    const int n=(int)T.size(),m=(int)P.size();
    for(int i=0,j=0;i<n;i++){
        if(j>=m)j=nxt[j-1];
        while(j>0&&T[i]!=P[j])j=nxt[j-1];
        if(T[i]==P[j])j++;
        if(j==m)ans.push_back(i-m+2);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,K;cin>>N>>K;
    vector<vector<int> >arr(N+N);
    for(int i=0;i<N;i++){
        int M;cin>>M;
        arr[i].resize(M);
        for(int j=0;j<M;j++)cin>>arr[i][j];
        arr[i+N]=vector<int>(arr[i].rbegin(),arr[i].rend());
    }
    bool flag=false;
    const int m=(int)arr.front().size();
    for(int i=0;i+K<=m;i++){
        vector<int>P(arr.front().begin()+i,arr.front().begin()+i+K);
        bool cur=true;
        for(int j=1;j<N;j++){
            cur&=!kmp(arr[j],P).empty()||!kmp(arr[j+N],P).empty();
        }
        flag|=cur;
    }
    cout<<(flag?"YES\n":"NO\n");
    return 0;
}
