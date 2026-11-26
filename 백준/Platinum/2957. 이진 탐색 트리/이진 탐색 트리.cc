#include "bits/stdc++.h"
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N;cin>>N;
    ll C=0;
    set<pair<int,int> >S;
    while(N--){
        int x;cin>>x;
        auto p=S.upper_bound({x,-1});
        int left = -1, right = -1;
        if(p != S.end()) right = p->second;
        if(p!=S.begin()){
            auto q=p; --q;
            left = q->second;
        }
        
        int cur = max(left,right) + 1;
        C+=cur;
        
        S.emplace_hint(p,x,cur);
        
        cout<<C<<"\n";
    }
    
    return 0;
}
