#include "bits/stdc++.h"
using namespace std;
using ll=long long;
constexpr ll mod=1e9+7;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    ll cnt=0,ans=0;
    for(int i=1;i<=N;i++){
        char c;cin>>c;
        if(c=='0'){
            ans+=cnt*(cnt+1)>>1;
            cnt=0;
        }else{
            cnt++;
        }
    }
    ans+=cnt*(cnt+1)>>1;
    cout<<ans<<"\n";
    return 0;
}
