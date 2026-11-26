#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll=long long;
constexpr ll q=17,p=1e9+7;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,L;cin>>N>>L;
    ll t;cin>>t;
    ll e=1;
    vector<ll>ans(N+3);
    for(int i=1;i<L;i++)e=e*q%p;
    for(int i=L+1;i<=N;i++){
        ll x;cin>>x;
        for(ll u=0;u<10;u++){
            for(ll v=0;v<10;v++){
                ll cur=((t-u*e%p+p)%p*q%p+v)%p;
                if(cur==x){
                    ans[i-L]=u;
                    ans[i]=v;
                    goto Next;
                }
            }
        }
        Next:{
            t=x;
        }
    }
    for(int i=1;i<=N;i++)cout<<ans[i];
    cout<<"\n";
    return 0;
}
