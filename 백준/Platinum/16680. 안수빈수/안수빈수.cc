#include "bits/stdc++.h"
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int T;cin>>T;
    while(T--){
        long long N;cin>>N;
        long long v=N*10000000000-N;
        int x=0;
        while(v){
            x=(x+v%10)&1;
            v/=10;
        }
        if(x)cout<<N*10000000000-N<<"\n";
        else cout<<N*1000000000-N<<"\n";
    }
    return 0;
}
