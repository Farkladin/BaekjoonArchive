#include "bits/stdc++.h"
using namespace std;
using ll=long long;
using lf=double;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    lf X,Y;cin>>X>>Y;
    int N;cin>>N;
    lf ans=1000/Y*X;
    while(N--){
        lf x,y;cin>>x>>y;
        ans=min(ans,1000/y*x);
    }
    cout<<fixed<<setprecision(2)<<ans<<"\n";
    
    return 0;
}
