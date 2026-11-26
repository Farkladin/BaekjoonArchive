#include "bits/stdc++.h"
using namespace std;

vector<int>CPF(string &s){ // Compute Prefix Function
    const int n=(int)s.size();
    vector<int>nxt(n);
    for(int i=1,j=0;i<n;i++){
        while(j>0&&s[i]!=s[j])j=nxt[j-1];
        if(s[i]==s[j])nxt[i]=++j;
    }
    return nxt;
}

vector<int>KMP(string &T,string &P){
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
    string S;cin>>S;
    auto cpf=CPF(S);
    for(int i=0;i<(int)cpf.size();i++){
        int cur=i+1-cpf[i];
        if(cur>0&&(i+1)%cur==0&&(i+1)/cur>1){
            cout<<i+1<<" "<<(i+1)/cur<<"\n";
        }
    }
    return 0;
}
