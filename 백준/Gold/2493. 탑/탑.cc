#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
using ull=unsigned long long;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    stack<pair<int,int> >stk;
    for(int i=1;i<=N;i++){
        int x;cin>>x;
        while(!stk.empty()&&stk.top().fi<x)stk.pop();
        if(stk.empty())cout<<"0 ";
        else cout<<stk.top().se<<" ";
        stk.push({x,i});
    }
    cout<<"\n";
    
    return 0;
}
