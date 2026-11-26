#include "bits/stdc++.h"
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int T;cin>>T;
    while(T--){
        ll N,ans=0;cin>>N;
        bitset<60>bit(N);
        string bs=bit.to_string();
        for(char c:bs){
            ans*=3;
            if(c=='1')ans+=1;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
