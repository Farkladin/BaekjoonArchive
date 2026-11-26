#include "bits/stdc++.h"
using namespace std;
using ll=long long;
ll po2[65]={1},po3[40]={1};
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    for(ll i=1;i<=60;i++)po2[i]=po2[i-1]<<1;
    for(ll i=1;i<=38;i++)po3[i]=po3[i-1]*3;
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
        for(auto [a,b]:vp)cout<<po2[a]*po3[b]<<" ";
        cout<<"\n";
    }
    return 0;
}
