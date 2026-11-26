#include "bits/stdc++.h"
using namespace std;
using ll=long long;
constexpr int sz=1<<20;
constexpr ll mod=1e9+7;
ll seg[(sz<<1)|3];
ll segsum(int S,int E,int s,int e,int pos){
    if(S>e||s>E)return 1;
    if(S<=s&&e<=E)return seg[pos];
    const int mid=(s+e)>>1;
    return segsum(S,E,s,mid,pos*2)*segsum(S,E,mid+1,e,pos*2+1)%mod;
}
void upd(ll p,ll x){
    seg[p]=x;
    while(p>>=1)seg[p]=seg[p*2]*seg[p*2+1]%mod;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,M,K;cin>>N>>M>>K;
    for(int i=1;i<=N;i++){
        ll x;cin>>x;
        upd(i+sz-1,x);
    }
    M+=K;
    while(M--){
        ll a,b,c;cin>>a>>b>>c;
        if(a==1)upd(b+sz-1,c);
        else{
            if(b>c)swap(b,c);
            cout<<segsum((int)b,(int)c,1,sz,1)<<"\n";
        }
    }
    return 0;
}
