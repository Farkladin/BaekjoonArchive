#include "bits/stdc++.h"
using namespace std;

const int sz = 1<<18;
int seg[(sz<<1)|3];
void upd(int p,int w){
    p+=sz-1;
    seg[p]=w;
    while(p>>=1)seg[p]=seg[p*2]+seg[p*2+1];
}

int sfind(int x){
    int s=1,e=sz,pos=1;
    while(s<e){
        const int mid = (s+e)>>1;
        if(x>seg[pos*2]){
            x-=seg[pos*2];
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
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int N;cin>>N;
    for(int i=1; i<=N; ++i){
        int w; cin>>w;
        upd(i,w);
    }
    
    for(int i=N; i>0; --i){
        int p; cin>>p;
        
        int pos = sfind(p);
        cout<<pos<<" ";
        upd(pos,0);
    }
    
    cout<<"\n";
    
    return 0;
}
