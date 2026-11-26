#include "bits/stdc++.h"
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    ll sum=0;
    for(int i=1;i<=N;i++){
        ll x;cin>>x;
        cout<<x*i-sum<<" ";
        sum+=x*i-sum;
    }
    cout<<"\n";
    return 0;
}
