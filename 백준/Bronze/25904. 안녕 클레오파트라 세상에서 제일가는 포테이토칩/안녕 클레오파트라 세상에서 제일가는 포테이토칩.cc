#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,X;cin>>N>>X;
    vector<int>T(N+3);
    for(int i=1;i<=N;i++)cin>>T[i];
    int idx=1;
    while(1){
        if(T[idx]<X){
            cout<<idx<<"\n";
            return 0;
        }
        idx=idx%N+1;
        X++;
    }
    return 1;
}
