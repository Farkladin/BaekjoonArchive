#include "bits/stdc++.h"
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int T;cin>>T;
    while(T--){
        ll N;cin>>N;
        ll a=0;
        vector<pair<int,int> >vp;
        while(N){
            while(!(N&1)){
                a++;
                N>>=1;
            }
            ll b=0,t=1;
            while(N>=t*3){
                t*=3;
                b++;
            }
            N-=t;
            vp.push_back({a,b});
        }
        cout<<vp.size()<<"\n";
        for(auto [a,b]:vp)cout<<a<<" "<<b<<"\n";
    }
    return 0;
}
