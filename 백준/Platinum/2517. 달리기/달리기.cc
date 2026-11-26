#include "bits/stdc++.h"
using namespace std;
constexpr int sz = 1<<19;
int seg[(sz<<1)|3];
void add(int p,int dw){
    p+=sz-1;
    seg[p]+=dw;
    while(p>>=1){
        seg[p]=seg[p*2]+seg[p*2+1];
    }
}

int ssum(int S,int E,int s,int e,int pos){
    if(S>e || s>E)return 0;
    if(S<=s && e<=E)return seg[pos];
    const int mid = (s+e)>>1;
    return ssum(S,E,s,mid,pos*2) + ssum(S,E,mid+1,e,pos*2+1);
}

struct Type{
    int x,seq,val;
    Type(int x=0, int seq=0, int val=0): x(x), seq(seq), val(val) {}
};

inline bool cmp_x(const Type &a, const Type &b){
    return a.x < b.x;
}

Type arr[500003], brr[500003];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N; cin>>N;
    for(int i=1; i<=N; ++i){
        cin>>arr[i].x;
        arr[i].seq=i;
    }
    sort(arr+1,arr+1+N,cmp_x);
    for(int i=1; i<=N; ++i){
        if(arr[i].x==arr[i-1].x)arr[i].val=arr[i-1].val;
        else arr[i].val=arr[i-1].val+1;
    }
    for(int i=1; i<=N; ++i){
        brr[arr[i].seq]=arr[i];
    }
    
    for(int i=1; i<=N; ++i){
        cout<<i-ssum(1, brr[i].val-1, 1, sz, 1)<<"\n";
        add(brr[i].val, 1);
    }
    
    return 0;
}
