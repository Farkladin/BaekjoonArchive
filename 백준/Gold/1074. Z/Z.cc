#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll N,r,c;cin>>N>>r>>c;r++;c++;
    ll x1=1,x2=1<<N,y1=1,y2=1<<N;
    ll w=1<<(2*N),t=1<<(2*N);
    while(x1<x2){
        w>>=2;
        ll xm=(x1+x2)>>1,ym=(y1+y2)>>1;
        if(r<=xm){
            if(c<=ym){
                x2=xm;
                y2=ym;
                t-=3*w;
            }else{
                x2=xm;
                y1=ym+1;
                t-=2*w;
            }
        }else{
            if(c<=ym){
                x1=xm+1;
                y2=ym;
                t-=w;
            }else{
                x1=xm+1;
                y1=ym+1;
            }
        }
    }
    cout<<t-1<<"\n";
    return 0;
}
