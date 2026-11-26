#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cout<<fixed;
    cout.precision(10);
    int T;cin>>T;
    while(T--){
        int N;cin>>N;
        vector<pair<double,double> >arr(N+2);
        for(int i=0;i<N;i++)cin>>arr[i].fi>>arr[i].se;
        double ans=1e18;
        for(int bit=(1<<(N>>1))-1;bit<(1<<N);bit++){
            if(__builtin_popcount(bit)!=(N>>1))continue;
            pair<double,double>cur;
            for(int i=0;i<N;i++){
                if((1<<i)&bit){
                    cur.fi+=arr[i].fi;
                    cur.se+=arr[i].se;
                }else{
                    cur.fi-=arr[i].fi;
                    cur.se-=arr[i].se;
                }
            }
            ans=min(ans,sqrt(cur.fi*cur.fi+cur.se*cur.se));
        }
        cout<<ans<<"\n";
    }
    return 0;
}
