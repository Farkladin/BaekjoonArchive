#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
constexpr double PI=3.14159265358979323846;
constexpr double deg2rad=PI/180;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    while(N--){
        double T,X;cin>>T>>X;T*=100;
        double x=T*tan(deg2rad*X),r=fmod(x,85.0);
        if(r>42.5)r=85.0-r;
        cout<<(r<=16.0/cos(deg2rad*X)?"yes\n":"no\n");
    }
    return 0;
}
