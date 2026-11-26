#include "bits/stdc++.h"
using namespace std;

constexpr int sz = 1<<19;
int seg[(sz<<1)|3], lazy[(sz<<1)|3];

void propagate(int s,int e,int pos){
    int &cur = lazy[pos];
    if(cur){
        int le=pos<<1, ri=(pos<<1)|1;
        if(s<e){
            lazy[le]^=cur;
            lazy[ri]^=cur;
        }
        if((e-s+1)&1)seg[pos]^=cur;
        cur=0;
    }
}

void uxor(int S,int E,int s,int e,int pos,int k){
    propagate(s,e,pos);
    if(S>e || s>E) return;
    if(S<=s && e<=E){
        lazy[pos]^=k;
        propagate(s,e,pos);
        return;
    }
    
    const int mid = (s+e)>>1;
    uxor(S,E,s,mid,pos*2,k);
    uxor(S,E,mid+1,e,pos*2+1,k);
    
    if(s<e) seg[pos]=seg[pos*2]^seg[pos*2+1];
}

int sxor(int S,int E,int s,int e,int pos){
    propagate(s,e,pos);
    if(S>e || s>E) return 0;
    if(S<=s && e<=E) return seg[pos];
    const int mid = (s+e)>>1;
    return sxor(S,E,s,mid,pos*2)^sxor(S,E,mid+1,e,pos*2+1);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N; cin>>N;
    
    for(int i=1; i<=N; ++i){
        int x; cin>>x;
        uxor(i,i,1,sz,1,x);
    }
    
    int M; cin>>M;
    while(M--){
        int q; cin>>q;
        if(q==2){
            int i,j; cin>>i>>j;
            cout<<sxor(i+1,j+1,1,sz,1)<<"\n";
        }else{
            int i,j,k; cin>>i>>j>>k;
            uxor(i+1,j+1,1,sz,1,k);
        }
    }
    
    return 0;
}
