#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll H,W,f,c,x1,y1,x2,y2;cin>>W>>H>>f>>c>>x1>>y1>>x2>>y2;
    
    c++;
    ll tmp=f+f;
    if(tmp>W){
        f=W-f;
        tmp=f+f;
        x1+=f;
        x2+=f;
    }else{
        x1+=f;x2+=f;
    }
    if(tmp>=x2){
        cout<<H*W-(x2-x1)*(y2-y1)*c*2<<"\n";
    }else if(tmp>=x1){
        cout<<H*W-(x2-x1)*(y2-y1)*c-(tmp-x1)*(y2-y1)*c<<"\n";
    }else{
        cout<<H*W-(x2-x1)*(y2-y1)*c<<"\n";
    }
    return 0;
}
