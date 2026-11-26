#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int T;cin>>T;
    while(T--){
        int R;string S;
        cin>>R>>S;
        for(auto c:S){
            cout<<string(R,c);
        }
        cout<<"\n";
    }
    return 0;
}
