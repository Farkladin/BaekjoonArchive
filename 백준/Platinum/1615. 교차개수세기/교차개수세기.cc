#include "bits/stdc++.h"
using namespace std;

constexpr int sz = 2048;
int seg[(sz<<1)|3];
vector<vector<int> >arr;

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
    
    int N,M; cin>>N>>M;
    arr.resize(N+3);
    for(int i=1;i<=M;++i){
        int a,b; cin>>a>>b;
        arr[b].push_back(a);
    }
    
    for(int i=1; i<=N; ++i){
        sort(arr[i].begin(),arr[i].end());
    }
    
    long long ans=0;
    for(int i=1; i<=N; ++i){
        for(int x:arr[i]){
            ans+=ssum(x+1,N,1,sz,1);
            add(x,1);
        }
    }
    cout<<ans<<"\n";
    return 0;
}
