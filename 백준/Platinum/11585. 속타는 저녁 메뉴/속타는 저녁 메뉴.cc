#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
vector<int>CPF(vector<char>&s){ // Compute Prefix Function
    const int n=(int)s.size();
    vector<int>nxt(n);
    for(int i=1,j=0;i<n;i++){
        while(j>0&&s[i]!=s[j])j=nxt[j-1];
        if(s[i]==s[j])nxt[i]=++j;
    }
    return nxt;
}

vector<int>KMP(vector<char>&T,vector<char>&P){
    vector<int>next=CPF(P),ans;
    const int n=(int)T.size(),m=(int)P.size();
    for(int i=0,j=0;i<n;i++){
        while(j>0&&T[i]!=P[j])j=next[j-1];
        if(T[i]==P[j])j++;
        if(j==m){
            ans.push_back(i-m+2); // Position where P appears in T
            j=next[j-1];
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    vector<char>T(N+N),P(N);
    for(int i=0;i<N;i++)cin>>P[i];
    for(int j=0;j<N;j++){
        cin>>T[j];
        T[j+N]=T[j];
    }
    T.pop_back();
    int t=(int)KMP(T,P).size();
    
    int div=gcd(t,N);
    cout<<t/div<<"/"<<N/div<<"\n";
    return 0;
}
