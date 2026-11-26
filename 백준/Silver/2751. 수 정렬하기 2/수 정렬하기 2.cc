#include "bits/stdc++.h"
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    vector<int>arr(N);
    for(auto &x:arr)cin>>x;
    sort(arr.begin(),arr.end());
    for(auto &x:arr)cout<<x<<"\n";
    return 0;
}
