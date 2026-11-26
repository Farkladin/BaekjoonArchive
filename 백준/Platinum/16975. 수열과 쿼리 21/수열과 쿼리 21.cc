#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;

const int sz = 1<<17;
ll seg[(sz<<1)|3];
void add(int p,ll dw){
    p+=sz-1;
    seg[p]+=dw;
    while(p>>=1){
        seg[p]=seg[p*2]+seg[p*2+1];
    }
}

ll ssum(int S,int E,int s,int e,int pos){
    if(S>e||s>E)return 0;
    if(S<=s&&e<=E)return seg[pos];
    const int mid = (s+e)>>1;
    return ssum(S,E,s,mid,pos*2) + ssum(S,E,mid+1,e,pos*2+1);
}

ll A[100003];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int N; cin>>N;
    for(int i=1; i<=N; ++i){
        cin>>A[i];
    }
    
    int M; cin>>M;
    while(M--){
        int q; cin>>q;
        if(q==1){
            int i,j,k; cin>>i>>j>>k;
            add(i,k);
            add(j+1,-k);
        }else{
            int x; cin>>x;
            cout<<ssum(1,x,1,sz,1)+A[x]<<"\n";
        }
    }
    
    return 0;
}
