#include "bits/stdc++.h"
using namespace std;
using ll = long long;

constexpr int sz=1<<20;
ll seg[(sz<<1)|3],seg2[(sz<<1)|3],B;

ll ssum(int S,int E,int s,int e,int pos){
    if(S>e||s>E)return 0;
    if(S<=s && e<=E)return seg[pos];
    const int mid=(s+e)>>1;
    return ssum(S,E,s,mid,pos*2)+ssum(S,E,mid+1,e,pos*2+1);
}

ll ssum2(int S,int E,int s,int e,int pos){
    if(S>e||s>E)return 0;
    if(S<=s && e<=E)return seg2[pos];
    const int mid=(s+e)>>1;
    return ssum2(S,E,s,mid,pos*2)+ssum2(S,E,mid+1,e,pos*2+1);
}

int sfind(int x){
    int s=1,e=sz,pos=1;
    while(s<e){
        const int mid=(s+e)>>1;
        if(seg[pos*2]<x){
            x-=seg[pos*2];
            s=mid+1;
            pos=pos*2+1;
        }else{
            e=mid;
            pos*=2;
        }
    }
    return s;
}

void add(ll p,ll dw){
    p+=sz-1;
    seg[p]+=dw;
    seg2[p]+=p-sz+1;
    while(p>>=1){
        seg[p]=seg[p*2]+seg[p*2+1];
        seg2[p]=seg2[p*2]+seg2[p*2+1];
    }
}

void solve(){
    memset(seg,0,sizeof(seg));
    memset(seg2,0,sizeof(seg2));
    B=-500000;
    
    int N,M; cin>>N>>M;
    for(int i=1;i<=N;++i){
        int V; cin>>V;
        add(V-B,1);
    }
    
    while(M--){
        int Q,W; cin>>Q>>W;
        switch(Q){
            case 1:
                add(W-B,1);
                ++N;
                break;
            case 2:
                B+=W;
                break;
            case 3:{
                int p=sfind(N-W);
                ll sum=ssum2(1,p-1,1,sz,1) + p*(N-W-ssum(1,p-1,1,sz,1));
                cout<<seg2[1]-sum+B*W<<" ";
                break;
            }
            case 4:{
                int p=sfind(W);
                ll sum=ssum2(1,p-1,1,sz,1) + p*(W-ssum(1,p-1,1,sz,1));
                cout<<sum+B*W<<" ";
                break;
            }
        }
    }
    cout<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int T;cin>>T;
    while(T--)solve();
    
    return 0;
}
