#include "bits/stdc++.h"
using namespace std;
int R[103];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;cin>>n;
    vector<int>arr(n);
    for(auto &x:arr){
        cin>>x;
        R[x]++;
    }
    for(int i=100;i>=0;i--){
        R[i]+=R[i+1];
    }
    for(auto &x:arr){
        cout<<R[x+1]+1<<"\n";
    }
    return 0;
}
