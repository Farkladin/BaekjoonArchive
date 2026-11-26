#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    vector<ll>L(N*2+3);
    ll cir=0;
    for(int i=1;i<=N;i++){
        cin>>L[i];
        L[N+i]=L[i];
        cir+=L[i];
    }
    if(cir&1){
        cout<<"N\n";
        return 0;
    }
    cir>>=1;
    ll cnt=0,len=0;
    for(int le=1,ri=0;le<=N;le++){
        while(len<cir)len+=L[++ri];
        if(len==cir)cnt++;
        len-=L[le];
    }
    cout<<(cnt>=4?"Y\n":"N\n");
    return 0;
}
