#include "bits/stdc++.h"
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,m;cin>>n>>m;
    cout<<gcd(n,m)<<"\n"<<n*m/gcd(n,m)<<"\n";
    return 0;
}
