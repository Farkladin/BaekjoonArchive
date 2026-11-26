#include "bits/stdc++.h"
using namespace std;
using u64=uint64_t;
constexpr int sz=131072;
int seg[(sz>>6)|3];
u64 lazy[(sz>>11)|3],leaf[(sz>>6)|3];

inline int mod64(const int &x){
    return x-((x>>6)<<6);
}

void h(int s,int e){
    if(s>e)return;
    int l=mod64(s),r=mod64(e);
    int sh=r-l+1;
    u64 bit=sh==64?(~0ULL):(((1ULL<<sh)-1)<<l);
    leaf[s>>6]^=bit;
}

void g(int s,int e,int pos){
    
    u64 bit=1ULL<<mod64(pos);
    if((lazy[pos>>6]&bit)==0)return;
    int mid=(s+e)>>1;
    
    // LEFT
    if(((s-1)>>6)==((mid-1)>>6)){
        h(s-1,mid-1);
    }else{
        int p=pos<<1;
        lazy[p>>6]^=1ULL<<mod64(p);
        seg[p]=mid-s+1-seg[p];
    }
    
    // RIGHT
    if((mid>>6)==((e-1)>>6)){
        h(mid,e-1);
    }else{
        int p=(pos<<1)|1;
        lazy[p>>6]^=1ULL<<mod64(p);
        seg[p]=(e-mid)-seg[p];
    }
    
    lazy[pos>>6]&=~bit;
}

int ssum(int S,int E,int s,int e,int pos){
    if(S>e||s>E)return 0;
    if(((s-1)>>6)<((e-1)>>6))g(s,e,pos);
    if(((s-1)>>6)==((e-1)>>6)){
        int l=max(s,S)-1,r=min(e,E)-1;
        int p=l>>6;
        l=mod64(l);r=mod64(r);
        
        int sh=r-l+1;
        u64 bit=sh==64?(~0ULL):(((1ULL<<sh)-1)<<l);
        
        return __builtin_popcountll(leaf[p]&bit);
    }
    
    if(S<=s&&e<=E)return seg[pos];
    
    int mid=(s+e)>>1;
    return ssum(S,E,s,mid,pos<<1)+ssum(S,E,mid+1,e,(pos<<1)|1);
}

void upd(int S,int E,int s,int e,int pos){
    if(S>e||s>E)return;
    if(((s-1)>>6)<((e-1)>>6))g(s,e,pos);
    
    if(((s-1)>>6)==((e-1)>>6)){
        int l=max(s,S)-1,r=min(e,E)-1;
        int pp=l>>6;
        l=mod64(l);r=mod64(r);
        int tmp=__builtin_popcountll(leaf[pp]);
        int sh=r-l+1;
        
        u64 bit=sh==64?(~0ULL):(((1ULL<<sh)-1)<<l);
        leaf[pp]^=bit;
        int p=pos,dw=__builtin_popcountll(leaf[pp])-tmp;
        while(p>>=1)seg[p]+=dw;
        return;
    }
    
    if(S<=s&&e<=E){
        int p=pos,dw=(e-s+1)-(seg[pos]<<1);
        u64 bit=1ULL<<mod64(pos);
        lazy[pos>>6]^=bit;
        seg[pos]=(e-s+1)-seg[pos];
        while(p>>=1)seg[p]+=dw;
        return;
    }
    
    int mid=(s+e)>>1;
    upd(S,E,s,mid,pos<<1);
    upd(S,E,mid+1,e,(pos<<1)|1);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,Q;cin>>N>>Q;
    while(Q--){
        int q,L,R;cin>>q>>L>>R;
        if(q==0)upd(L,R,1,sz,1);
        else cout<<ssum(L,R,1,sz,1)<<"\n";
    }
    return 0;
}
