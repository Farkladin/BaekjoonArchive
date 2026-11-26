#include "bits/stdc++.h"
using namespace std;

void solve(){
    int N,L,k; cin>>N>>L>>k;
    vector<pair<int,int> >arr(N);
    queue<int>dec,inc;
    
    for(auto &[garb,a]:arr){
        int p; cin>>p>>a;
        if(a<0)dec.push(p);
        else inc.push(L-p);
    }
    
    int it=0;
    while(!dec.empty()){
        arr[it++].first = dec.front(); dec.pop();
    }
    while(!inc.empty()){
        arr[it++].first = inc.front(); inc.pop();
    }
    
    sort(arr.begin(),arr.end());
    cout<<arr.at(k-1).second<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int T;cin>>T;
    while(T--)solve();
    return 0;
}
