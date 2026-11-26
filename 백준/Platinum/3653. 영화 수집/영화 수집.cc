#include "bits/stdc++.h"
using namespace std;

const int sz = 1<<18, zero = 100000;
int arr[100003], seg[(sz<<1)|3];
int ssum(int S,int E,int s,int e,int pos){
    if(S>e || s>E)return 0;
    if(S<=s && e<=E)return seg[pos];
    const int mid = (s+e)>>1;
    return ssum(S,E,s,mid,pos*2) + ssum(S,E,mid+1,e,pos*2+1);
}

void add(int p,int dw){
    p+=sz-1;
    seg[p]+=dw;
    while(p>>=1){
        seg[p]=seg[p*2]+seg[p*2+1];
    }
}

void solve(){
    memset(arr,0,sizeof(arr));
    memset(seg,0,sizeof(seg));
    int n,m; cin>>n>>m;
    for(int i=1; i<=n; ++i){
        arr[i]=i+zero;
        add(arr[i],1);
    }
    int t=0;
    while(m--){
        int x; cin>>x;
        cout<<ssum(1,arr[x]-1,1,sz,1)<<" ";
        add(arr[x],-1);
        arr[x]=t+zero;
        add(arr[x],1);
        --t;
    }
    cout<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T; cin>>T;
    while(T--)solve();
    return 0;
}
