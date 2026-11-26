#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    string a,b;cin>>a>>b;
    if(N&1){
        for(auto &x:a)x^=1;
    }
    cout<<(a==b?"Deletion succeeded\n":"Deletion failed\n");
    return 0;
}
