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
    vector<int>nxt=CPF(P),ans;
    const int n=(int)T.size(),m=(int)P.size();
    for(int i=0,j=0;i<n;i++){
        while(j>0&&T[i]!=P[j])j=nxt[j-1];
        if(T[i]==P[j])j++;
        if(j==m){
            ans.push_back(i-m+1); // Position where P appears in T
            j=nxt[j-1];
        }
    }
    return ans;
}

/*
 ABC
 CAB
 BCA
 */

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    string a,b,c;cin>>a>>b>>c;
    const int n = (int)a.size();
    a=a+a; b=b+b; c=c+c;
    a.pop_back(); b.pop_back(); c.pop_back();
    int ans=1e9;
    for(int i=0; i<n; ++i){
        string p(n,'#');
        bool flag=false;
        for(int j=0; j<n; ++j){
            if(a[j]==b[i+j]){
                flag=true;
                break;
            }
            if(a[j]=='A'){
                if(b[i+j]=='B')p[j]='C';
                else p[j]='B';
            }else if(a[j]=='B'){
                if(b[i+j]=='A')p[j]='C';
                else p[j]='A';
            }else{
                if(b[i+j]=='A')p[j]='B';
                else p[j]='A';
            }
        }
        if(flag)continue;
        
        vector<int>res(KMP(c,p));
        if(!res.empty()){
            ans=min(ans, min(i,n-i) + min(res.front(), n-res.back()));
        }
    }
    
    for(int i=0; i<n; ++i){
        string p(n,'#');
        bool flag=false;
        for(int j=0; j<n; ++j){
            if(a[j]==b[i+j]){
                flag=true;
                break;
            }
            if(a[j]=='A'){
                if(b[i+j]=='B')p[j]='C';
                else p[j]='B';
            }else if(a[j]=='B'){
                if(b[i+j]=='A')p[j]='C';
                else p[j]='A';
            }else{
                if(b[i+j]=='A')p[j]='B';
                else p[j]='A';
            }
        }
        if(flag)continue;
        
        vector<int>res(KMP(c,p));
        if(!res.empty()){
            ans=min(ans, min(i,n-i) + min(res.front(), n-res.back()));
            ans=min(ans, i + res.front() - min(i,res.front()));
            ans=min(ans, n-i + n-res.back() - min(n-i,n-res.back()));
        }
    }
    if(ans==1e9)ans=-1;
    cout<<ans<<"\n";
    return 0;
}
