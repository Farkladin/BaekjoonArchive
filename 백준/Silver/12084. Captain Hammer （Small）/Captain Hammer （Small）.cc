#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
constexpr double PI=3.14159265358979323846;
constexpr double g=9.8,radDeg=180/PI;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int T;cin>>T;
    cout<<fixed;
    cout.precision(10);
    for(int tc=1;tc<=T;tc++){
        cout<<"Case #"<<tc<<": ";
        double V,D;cin>>V>>D;
        double tmp=min(g*D/(V*V),1.0);
        cout<<asin(tmp)*0.5*radDeg<<"\n";
    }
    return 0;
}
