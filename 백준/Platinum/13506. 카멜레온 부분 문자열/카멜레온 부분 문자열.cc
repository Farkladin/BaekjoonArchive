#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;

vector<int>CPF(string s){
    const int n=(int)s.size();
    vector<int>nxt(n);
    for(int i=1,j=0;i<n;i++){
        while(j>0&&s[i]!=s[j])j=nxt[j-1];
        if(s[i]==s[j])nxt[i]=++j;
    }
    return nxt;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    string s;cin>>s;
    vector<int>nxt1=CPF(s),nxt2=CPF(string(s.rbegin(),s.rend()));
    const int n=(int)s.size();
    int ans=0;
    for(int i=1;i<n;i++){
        int cur=nxt1[i];
        if(n-i+cur-2>=0&&cur==nxt2[n-i+cur-2]){
            ans=max(ans,cur);
        }
    }
    cout<<(ans==0?"-1":string(s.begin(),s.begin()+ans))<<"\n";
    return 0;
}
