#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // 1 2* 3 4 5 6 7* 8 9* 10 11 12 13 14* 15 16* 17 18 19 20
    // 2 7 9 14 16
    ll N;cin>>N;
    bool ans=false;
    if(N<7)ans=N==2;
    else{
        ans=N%7==0||N%7==2;
    }
    cout<<(ans?"CY\n":"SK\n");
    return 0;
}
