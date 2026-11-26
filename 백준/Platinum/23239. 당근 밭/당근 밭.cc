#include "bits/stdc++.h"
using namespace std;
using ll=long long;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll w,h,L;cin>>w>>h>>L;
    ll ans=0;
    for(ll i=0;i<L;i++)
    {
        ll t=L*L-i*i;
        if(t<0)break;
        ll r=sqrt(t)-1;
        while(i*i+(r+1)*(r+1)<=L*L)r++;
        if(i==0)ans+=r*2;
        else ans+=r*3;
    }
    for(ll i=0;i<L-h;i++){
        ll t=(L-h)*(L-h)-i*i;
        if(t<0)break;
        ll r=sqrt(t)-1;
        while(i*i+(r+1)*(r+1)<=(L-h)*(L-h))r++;
        ans+=r;
    }
    for(ll i=0;i<L-w;i++)
    {
        ll t=(L-w)*(L-w)-i*i;
        if(t<0)break;
        ll r=sqrt(t)-1;
        while(i*i+(r+1)*(r+1)<=(L-w)*(L-w))r++;
        ans+=r;
    }
    
    for(ll i=1;i<L-h-w;i++){
        ll t=(L-w)*(L-w)-i*i;
        ll s=(L-h)*(L-h)-(i+w)*(i+w);
        ll r=sqrt(t)-1;
        while(i*i+(r+1)*(r+1)<=(L-w)*(L-w))r++;
        ll rr=sqrt(s)-1;
        while((i+w)*(i+w)+(rr+1)*(rr+1)<=(L-h)*(L-h))rr++;
        ans-=min(r-h,rr);
    }
    cout<<ans<<"\n";
    return 0;
}
