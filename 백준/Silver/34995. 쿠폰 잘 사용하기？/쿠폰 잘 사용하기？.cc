#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    string a,b;cin>>a>>b;
    for(auto &x:a){
        if(x=='?')x='9';
    }
    for(auto &x:b){
        if(x=='?')x='1';
    }
    if(a.size()>b.size())cout<<a<<"\n";
    else if(a.size()<b.size())cout<<"-1\n";
    else if(a>=b)cout<<a<<"\n";
    else cout<<"-1\n";
    return 0;
}
