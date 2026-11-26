#include "bits/stdc++.h"
using namespace std;
using ll=long long;
#define fi first
#define se second

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    string S,T;cin>>S>>T;
    while(T.size()>S.size()){
        if(T.back()=='A')T.pop_back();
        else{
            T.pop_back();
            reverse(T.begin(),T.end());
        }
    }
    cout<<(S==T)<<"\n";
    return 0;
}
