#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cout<<fixed;
    cout.precision(2);
    while(1){
        double x;cin>>x;
        if(x==0)break;
        cout<<1+x+x*x+x*x*x+x*x*x*x<<"\n";
    }
    return 0;
}
