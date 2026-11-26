#include "bits/stdc++.h"
using namespace std;

constexpr int sz = 1<<17;
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
    return ssum(S,E,s,mid,pos*2)+ssum(S,E,mid+1,e,pos*2+1);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int T;cin>>T;
    while(T--){
        memset(seg,0,sizeof(seg));
        int N; cin>>N;
        vector<int>arr(N+3);
        for(int i=1;i<=N;++i){
            int x;cin>>x;
            arr[x]=i;
        }
        
        long long ans=0;
        for(int i=1; i<=N; ++i){
            int x; cin>>x;
            ans+=ssum(arr[x]+1,N,1,sz,1);
            add(arr[x],1);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
