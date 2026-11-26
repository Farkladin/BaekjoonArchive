#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int a=0,b=0,c=0,d=0,e=0,f=0;
    int N;cin>>N;
    while(N--){
        int x,y,z;cin>>x>>y>>z;
        int ta,tb,tc,td,te,tf;
        ta=x+max(a,b);
        tb=y+max({a,b,c});
        tc=z+max(b,c);
        td=x+min(d,e);
        te=y+min({d,e,f});
        tf=z+min(e,f);
        a=ta;b=tb;c=tc;d=td;e=te;f=tf;
    }
    cout<<max({a,b,c})<<" "<<min({d,e,f})<<"\n";
    return 0;
}
