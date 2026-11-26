#include "bits/stdc++.h"
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int T;cin>>T;
    while(T--){
        bool ans=true;
        int x=0;
        string s;cin>>s;
        for(char c:s){
            if(c=='(')x++;
            else x--;
            if(x<0)ans=false;
        }
        if(x!=0)ans=false;
        cout<<(ans?"YES\n":"NO\n");
    }
    return 0;
}
