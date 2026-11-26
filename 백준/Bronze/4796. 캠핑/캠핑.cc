#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int cnt[103],idx[103];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tc=0;
    while(1){
        tc++;
        int L,P,V;cin>>L>>P>>V;
        if(L==0&&P==0&&V==0)break;
        cout<<format("Case {:d}: {:d}",tc,V/P*L+min(V%P,L))<<"\n";
    }
    return 0;
}
