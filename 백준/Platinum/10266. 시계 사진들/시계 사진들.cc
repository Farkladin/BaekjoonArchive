#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;

vector<int>CPF(vector<int> &s){ // Compute Prefix Function
    const int n=(int)s.size();
    vector<int>nxt(n);
    for(int i=1,j=0;i<n;i++){
        while(j>0&&s[i]!=s[j])j=nxt[j-1];
        if(s[i]==s[j])nxt[i]=++j;
    }
    return nxt;
}

vector<int>KMP(vector<int> &T,vector<int> &P){
    vector<int>next=CPF(P),ans;
    const int n=(int)T.size(),m=(int)P.size();
    for(int i=0,j=0;i<n;i++){
        while(j>0&&(j==m||T[i]!=P[j]))j=next[j-1];
        if(T[i]==P[j])j++;
        if(j==m)ans.push_back(i-m+2); // Position where P appears in T
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;cin>>n;
    vector<int>T(n),P(n),arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        int j=i+1>=n?0:i+1;
        T[i]=arr[j]-arr[i]+(j==0?360000:0);
    }
    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        int j=i+1>=n?0:i+1;
        P[i]=arr[j]-arr[i]+(j==0?360000:0);
    }
    for(int i=0;i<n;i++)T.push_back(T[i]);
    vector<int>res=KMP(T,P);
    
    cout<<(res.empty()?"impossible\n":"possible\n");
    return 0;
}
