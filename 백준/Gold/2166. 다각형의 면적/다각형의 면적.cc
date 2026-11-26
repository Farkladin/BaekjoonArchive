#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<double,double>;

inline int CCW(const pii &a,const pii &b,const pii &c){
    ll tmp=a.fi*b.se+b.fi*c.se+c.fi*a.se-a.se*b.fi-b.se*c.fi-c.se*a.fi;
    return tmp<0?-1:(tmp==0?0:1);
}

inline double ccw(const pii &a,const pii &b,const pii &c){
    return a.fi*b.se+b.fi*c.se+c.fi*a.se-a.se*b.fi-b.se*c.fi-c.se*a.fi;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    cout<<fixed;
    cout.precision(1);
    pii a,b;cin>>a.fi>>a.se>>b.fi>>b.se;
    double ans=0;
    for(int i=3;i<=N;i++){
        pii c;cin>>c.fi>>c.se;
        ans+=ccw(a,b,c);
        b=c;
    }
    cout<<abs(ans)*0.5<<"\n";
    return 0;
}
