#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int T;cin>>T;
    while(T--){
        ll N;cin>>N;
        int X;cin>>X;
        bool flag=true;
        set<ll>pre={0};
        for(int i=1;i<=X;i++){
            ll P;cin>>P;
            set<ll>cur;
            for(auto x:pre){
                if(x>P)cur.insert(x);
                if(x<P){
                    cur.insert(P+3);
                    if(x<P-1)cur.insert(P+2);
                    if(x<P-2)cur.insert(P+1);
                }
            }
            if(cur.empty())flag=false;
            pre=cur;
        }
        cout<<(flag?"POSSIBLE\n":"IMPOSSIBLE\n");
    }
    return 0;
}
