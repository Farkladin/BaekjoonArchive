#include "bits/stdc++.h"
using namespace std;
using ll=long long;
constexpr int sz=1<<20;
ll seg[(sz<<1)|3];
ll segsum(int S,int E,int s,int e,int pos){
    if(S>e||s>E)return ll(1e9);
    if(S<=s&&e<=E)return seg[pos];
    const int mid=(s+e)>>1;
    return min(segsum(S,E,s,mid,pos*2),segsum(S,E,mid+1,e,pos*2+1));
}
void upd(ll p,ll x){
    seg[p]=x;
    while(p>>=1)seg[p]=min(seg[p*2],seg[p*2+1]);
}
int main(){
    fill(seg,seg+1+sz*2,ll(1e9));
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,M;cin>>N>>M;
    for(int i=1;i<=N;i++){
        ll x;cin>>x;
        upd(i+sz-1,x);
    }
    while(M--){
        ll a,b;cin>>a>>b;
        if(a>b)swap(a,b);
        cout<<segsum((int)a,(int)b,1,sz,1)<<"\n";
    }
    return 0;
}
