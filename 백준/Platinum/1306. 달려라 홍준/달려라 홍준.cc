#include "bits/stdc++.h"
using namespace std;
using ll=long long;
constexpr int sz = 1<<20;

int arr[1000003];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    
    int N,M;cin>>N>>M;
    multiset<int>ms;
    for(int i=1;i<M+M-1;++i){
        cin>>arr[i];
        ms.insert(arr[i]);
    }
    
    for(int i=M+M-1;i<=N;i++){
        cin>>arr[i];
        ms.insert(arr[i]);
        cout<<(*ms.rbegin())<<" ";
        ms.erase(ms.find(arr[i-M-M+2]));
    }
    cout<<"\n";
    return 0;
}
