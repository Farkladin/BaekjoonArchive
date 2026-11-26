#include "bits/stdc++.h"
using namespace std;
using ll=long long;
ll A[100003];
ll f(ll s,ll e){
    if(s>e)return 0;
    if(s==e)return A[s]*A[s];
    ll mid=(s+e)>>1;
    ll vl=f(s,mid),vr=f(mid+1,e),v=A[mid]*A[mid],sum=A[mid],mn=A[mid],l=mid,r=mid;
    while(s<l||r<e){
        if(l==s)goto extendRight;
        if(r==e)goto extendLeft;
        if(A[l-1]>A[r+1])goto extendLeft;
        else goto extendRight;
        
        extendLeft:{
            l--;
            sum+=A[l];
            mn=min(A[l],mn);
            v=max(mn*sum,v);
            continue;
        }
        extendRight:{
            r++;
            sum+=A[r];
            mn=min(A[r],mn);
            v=max(mn*sum,v);
            continue;
        }
    }
    
    return max({vl,vr,v});
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    for(int i=1;i<=N;i++)cin>>A[i];
    cout<<f(1,N)<<"\n";
    return 0;
}
