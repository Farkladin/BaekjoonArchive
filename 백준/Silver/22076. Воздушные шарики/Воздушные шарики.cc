#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,k;cin>>n>>k;
    multiset<int>ms;
    set<int>s;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        ms.insert(x);
        s.insert(x);
    }
    while(k--){
        if(!s.empty()){
            auto it=s.begin();
            cout<<*it<<" ";
            ms.erase(ms.find(*it));
            s.erase(it);
        }else{
            cout<<*ms.begin()<<" ";
            ms.erase(ms.begin());
        }
    }
    cout<<"\n";
    return 0;
}
