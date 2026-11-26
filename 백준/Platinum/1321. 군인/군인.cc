#include "bits/stdc++.h"
using namespace std;
constexpr int sz = 1<<19;
int seg[(sz<<1)|3];

void add(int p,int dw){
    p+=sz-1;
    seg[p]+=dw;
    while(p>>=1)seg[p]=seg[p*2]+seg[p*2+1];
}

int sfind(int x){
    int s=1,e=sz,pos=1;
    while(s<e){
        const int mid=(s+e)>>1;
        if(seg[pos*2]<x){
            x-=seg[pos*2];
            s=mid+1;
            pos = pos*2 + 1;
        }else{
            e=mid;
            pos = pos*2;
        }
    }
    return pos-sz+1;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    for(int i=1;i<=N;i++){
        int x;cin>>x;
        add(i,x);
    }
    int M;cin>>M;
    while(M--){
        int q,id;cin>>q>>id;
        if(q==1){
            int a;cin>>a;
            add(id,a);
        }else{
            cout<<sfind(id)<<"\n";
        }
    }
    
    return 0;
}
