#include "bits/stdc++.h"
using namespace std;

vector<int>CPF(vector<int> &s){ // Compute Prefix Function
    const int n=(int)s.size();
    vector<int>nxt(n);
    for(int i=1,j=0;i<n;++i){
        while(j>0&&s[i]!=s[j])j=nxt[j-1];
        if(s[i]==s[j])nxt[i]=++j;
    }
    return nxt;
}

bool KMP(vector<int> &T, vector<int> &P){
    vector<int>nxt=CPF(P);
    const int n=(int)T.size(),m=(int)P.size();
    for(int i=0,j=0; i<n; ++i){
        while(j>0&&T[i]!=P[j])j=nxt[j-1];
        if(T[i]==P[j]) ++j;
        if(j==m){
            return true;
        }
    }
    return false;
}

vector<int> arr[1003], P;
int brr[100003];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int N; cin>>N;
    for(int i=1; i<=N; ++i){
        int K; cin>>K;
        cin>>brr[0];
        arr[i].reserve(K-1);
        for(int j=1; j<K; ++j){
            cin>>brr[j];
            arr[i].push_back(brr[j]-brr[j-1]);
        }
    }
    
    int L; cin>>L;
    P.reserve(L-1); cin>>brr[0];
    for(int i=1; i<L; ++i){
        cin>>brr[i];
        P.push_back(brr[i]-brr[i-1]);
    }
    
    int flag=0;
    for(int i=1; i<=N; ++i){
        if(KMP(arr[i],P)){
            cout<<i<<" ";
            flag=1;
        }
    }
    if(!flag)cout<<"-1";
    cout<<"\n";
    
    return 0;
}
