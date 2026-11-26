#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll N;cin>>N;
    ll A,B,C,D,E,F;cin>>A>>B>>C>>D>>E>>F;
    if(N==1){
        cout<<A+B+C+D+E+F-max({A,B,C,D,E,F})<<"\n";
        return 0;
    }
    ll ans=min({A,B,C,D,E,F})*((N-1)*(N-2)*4+(N-2)*(N-2));
    ans+=min({A+B,A+C,A+D,A+E,B+C,B+D,B+F,C+E,C+F,D+E,D+F,E+F})*((N-1)*4+(N-2)*4);
    ans+=min({A+B+C,A+B+D,A+C+E,A+D+E,B+C+F,B+D+F,C+E+F,D+E+F})*4;
    cout<<ans<<"\n";
    return 0;
}
