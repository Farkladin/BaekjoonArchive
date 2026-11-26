#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,X;cin>>N>>X;
    for(int i=1;i<=N;i++){
        int x;cin>>x;
        if(x<X)cout<<x<<" ";
    }
    cout<<"\n";
    return 0;
}
