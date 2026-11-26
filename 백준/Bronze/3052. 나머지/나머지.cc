#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int arr[103];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    set<int>si;
    for(int i=1;i<=10;i++){
        int x;cin>>x;
        si.insert(x%42);
    }
    cout<<si.size()<<"\n";
    return 0;
}
