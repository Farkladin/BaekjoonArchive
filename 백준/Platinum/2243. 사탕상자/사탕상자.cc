#include "bits/stdc++.h"
using namespace std;
using ll=long long;
const int sz=1<<20;
ll seg[(sz<<1)|3];
void add(int p,ll dw){
    p+=sz-1;
    seg[p]+=dw;
    while(p>>=1){
        seg[p]=seg[p*2]+seg[p*2+1];
    }
}

int sfind(ll target,int s,int e,int pos){
    while(s<e){
        const int mid=(s+e)>>1;
        if(target>seg[pos*2]){
            target-=seg[pos*2];
            pos=pos*2+1;
            s=mid+1;
        }else{
            e=mid;
            pos=pos*2;
        }
    }
    return s;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;cin>>n;
    while(n--){
        ll A,B,C;cin>>A>>B;
        if(A==1){
            int pos=sfind(B,1,sz,1);
            cout<<pos<<"\n";
            add(pos,-1);
        }else{
            cin>>C;
            add((int)B,C);
        }
    }
    return 0;
}
