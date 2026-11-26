#include "bits/stdc++.h"
#include <format>
using namespace std;
using ll=long long;
ll A[100003];

struct Data{
    ll s,e,v;
    Data(ll s=0,ll e=0,ll v=0):s(s),e(e),v(v){}
    const bool operator<(const Data &rhs)const{
        return v<rhs.v;
    }
};

Data f(ll s,ll e){
    if(s>e)return Data(0,0,-2e18);
    if(s==e)return Data(s,e,A[s]*A[s]);
    ll mid=(s+e)>>1;
    Data vl=f(s,mid),vr=f(mid+1,e);
    ll sum=A[mid],mn=A[mid],l=mid,r=mid;
    Data v(mid,mid,A[mid]*A[mid]);
    while(s<l||r<e){
        if(l==s)goto extendRight;
        if(r==e)goto extendLeft;
        if(A[l-1]>A[r+1])goto extendLeft;
        else goto extendRight;
        
        extendLeft:{
            l--;
            sum+=A[l];
            mn=min(A[l],mn);
            if(v.v<mn*sum){
                v.v=mn*sum;
                v.s=l;
                v.e=r;
            }
            continue;
        }
        extendRight:{
            r++;
            sum+=A[r];
            mn=min(A[r],mn);
            if(v.v<mn*sum){
                v.v=mn*sum;
                v.s=l;
                v.e=r;
            }
            continue;
        }
    }
    
    return max({vl,vr,v});
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    for(int i=1;i<=N;i++)cin>>A[i];
    Data ans=f(1,N);
    cout<<format("{:d}\n{:d} {:d}\n",ans.v,ans.s,ans.e);
    return 0;
}
