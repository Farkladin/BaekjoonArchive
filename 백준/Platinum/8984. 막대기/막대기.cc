#include "bits/stdc++.h"
using namespace std;
using ll=long long;
using pii = pair<ll,ll>;

vector<ll>D(100003);
vector<pii>A(100003);

map<ll,ll> mpb,mpt;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    
    ll N,L; cin>>N>>L;
    
    for(ll i=1;i<=N;i++)cin>>A[i].first>>A[i].second;
    
    sort(A.begin()+1,A.begin()+1+N);
    
    ll ans=0;
    
    for(ll i=1;i<=N;i++){
        ll sol=abs(A[i].first-A[i].second) + L;
        D[i]=sol;
        
        auto &btm=mpb[A[i].second];
        auto &tp=mpt[A[i].first];
        
        ll x=sol,y=sol;
        if(btm)x=max(x,sol+btm);
        if(tp)y=max(y,sol+tp);
        btm=max(btm,y);
        tp=max(tp,x);
        D[i]=max(x,y);
        ans = max(ans, D[i]);
    }
    
    cout<<ans<<endl;
    
    return 0;
}