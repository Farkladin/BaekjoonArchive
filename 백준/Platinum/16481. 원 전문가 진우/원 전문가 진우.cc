#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    double a,b,c;cin>>a>>b>>c;
    double rr=1/a+1/b+1/c;
    cout<<fixed<<setprecision(10)<<1/rr<<"\n";
    return 0;
}
