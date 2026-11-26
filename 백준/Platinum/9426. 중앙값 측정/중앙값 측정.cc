#include "bits/stdc++.h"
using namespace std;
using ll=long long;
constexpr int sz = 1<<18;
int seg[(sz<<1)|3],arr[250003];

void add(int p,int dw){
    p+=sz-1;
    seg[p]+=dw;
    while(p>>=1)seg[p]=seg[p*2]+seg[p*2+1];
}

int sfind(int x){
    int s=1,e=sz,pos=1;
    while(s<e){
        const int mid = (s+e)>>1;
        if(x>seg[pos*2]){
            x-=seg[pos*2];
            s=mid+1;
            pos=pos*2+1;
        }else{
            e=mid;
            pos=pos*2;
        }
    }
    return pos-sz+1;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    
    int N,K;cin>>N>>K;
    for(int i=1;i<K;++i){
        cin>>arr[i]; ++arr[i];
        add(arr[i],1);
    }
    long long ans=0;
    for(int i=K;i<=N;++i){
        cin>>arr[i]; ++arr[i];
        add(arr[i],1);
        
        ans += sfind((K+1)>>1)-1;
        add(arr[i-K+1],-1);
    }
    
    cout<<ans<<"\n";
    return 0;
}
