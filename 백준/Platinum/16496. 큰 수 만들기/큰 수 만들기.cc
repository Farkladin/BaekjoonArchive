#include "bits/stdc++.h"
using namespace std;

inline bool cmp1(const string &a, const string &b){
    return a.size()<b.size()||(a.size()==b.size()&&a<b);
}

inline bool cmp2(const string &a, const string &b){
    const string ab=a+b,ba=b+a;
    return ab>ba;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    vector<string>vec(N);
    
    string mx;
    for(string &x:vec){
        cin>>x;
        mx=max(mx,x,cmp1);
    }
    sort(vec.begin(),vec.end(),cmp2);
    string ans="";
    for(string &x:vec){
        ans+=x;
    }
    if(ans.front()=='0')ans="0";
    cout<<ans<<"\n";
    return 0;
}
