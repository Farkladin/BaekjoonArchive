#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    int a,b,c,d,e,f;cin>>a>>b>>c>>d>>e>>f;
    int t,p;cin>>t>>p;
    cout<<(a+t-1)/t+(b+t-1)/t+(c+t-1)/t+(d+t-1)/t+(e+t-1)/t+(f+t-1)/t<<"\n";
    cout<<N/p<<" "<<N%p<<"\n";
    return 0;
}
