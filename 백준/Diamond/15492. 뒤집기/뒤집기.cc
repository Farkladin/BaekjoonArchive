#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;

using ull=uint64_t;
constexpr ull p1=2147483647,p2=998244353,q1=101,q2=74747;

template<ull mod>
ull po(ull a,ull b){
    ull ret=1;
    while(b){
        if(b&1)ret=ret*a%mod;
        a=a*a%mod;b>>=1;
    }
    return ret;
}

ull poq1[4000003]={1},poq2[4000003]={1};
vector<ull>arr;
vector<pair<ull,ull> >hrr,brr;

pair<ull,ull> g(const ull ai,const ull le,const ull ri,const ull N){
    pair<ull,ull>ret;
    if(le+ai==0)return brr[0];
    ret.fi=(brr[ri+ai].fi+p1-brr[le+ai-1].fi*poq1[ri-le+1]%p1)%p1;
    ret.se=(brr[ri+ai].se+p2-brr[le+ai-1].se*poq2[ri-le+1]%p2)%p2;
    return ret;
}
bool cmp(const ull ai,const ull bi,const ull N){
    ull le=0,ri=N-1;
    if(ai==bi)return false;
    ull mid;
    while(le<ri){
        mid=(le+ri)>>1;
        // [le, mid], [mid+1, ri]
        pair<ull,ull>al{g(ai,le,mid,N)},bl{g(bi,le,mid,N)};
        if(al==bl)le=mid+1;
        else ri=mid;
    }
    return arr[(le+ai)%N]<arr[(le+bi)%N];
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    arr.resize(N+N);
    hrr.resize(N);brr.resize(N+N);
    for(int i=1;i<=N;i++){
        poq1[i]=poq1[i-1]*q1%p1;
        poq2[i]=poq2[i-1]*q2%p2;
    }

    for(int i=0;i<N;i++){
        cin>>arr[i];
        arr[i+N]=arr[i];
    }
    reverse(arr.begin(),arr.end());
    brr[0]={arr[0]%p1,arr[0]%p2};
    for(int i=1;i<N+N;i++){
        brr[i].fi=(brr[i-1].fi*q1%p1+arr[i]%p1)%p1;
        brr[i].se=(brr[i-1].se*q2%p2+arr[i]%p2)%p2;
    }
    
    for(int i=0;i<N;i++){
        hrr[i]=g(i,0,N-1,N);
    }
    
    pair<ull,ull>mx=hrr[1];
    int idx=1;
    
    for(int i=2;i<N;i++){
        if(cmp(i,idx,N)){
            mx=hrr[i];
            idx=i;
        }
    }
    
    for(int j=0;j<N;j++){
        cout<<arr[idx]<<" ";
        idx=idx+1==N?0:idx+1;
    }
    cout<<"\n";
    
    return 0;
}
