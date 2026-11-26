#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
inline ll dist(const pii &a,const pii &b){
    return abs(a.fi-b.fi)+abs(a.se-b.se);
}
constexpr ll dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    vector<pii>arr(N);
    for(auto &p:arr)cin>>p.fi>>p.se;
    pii s;cin>>s.fi>>s.se;
    bool flag=false;
    for(int i=0;i<4;i++){
        pii cur{s.fi+dx[i]*1e13,s.se+dy[i]*1e13};
        ll d=dist(cur,s);
        bool flagi=true;
        for(auto &p:arr){
            flagi&=dist(p,cur)>d;
        }
        flag|=flagi;
    }
    cout<<(flag?"YES\n":"NO\n");
    return 0;
}
