#include "bits/stdc++.h"
using namespace std;
const int sz=1<<19;
int seg[(sz<<1)|3];
int arr[1000003];

void add(int p,int dw){
    p+=sz-1;
    seg[p]+=dw;
    while(p>>=1)seg[p]=seg[p*2]+seg[p*2+1];
}

int ssum(int S,int E,int s,int e,int pos){
    if(S>e||s>E)return 0;
    if(S<=s&&e<=E)return seg[pos];
    const int mid=(s+e)>>1;
    return ssum(S,E,s,mid,pos*2)+ssum(S,E,mid+1,e,pos*2+1);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    for(int i=1;i<=N;i++){
        int x;cin>>x;
        arr[x]=i;
    }
    
    long long ans=0;
    for(int i=1;i<=N;i++){
        int x;cin>>x;
        int p=arr[x];
        ans+=ssum(p+1,N,1,sz,1);
        add(p,1);
    }
    cout<<ans<<"\n";
    return 0;
}
