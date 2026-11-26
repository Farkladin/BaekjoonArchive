#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int T;cin>>T;
    while(T--){
        string s;cin>>s;
        int a=0,b=0;
        for(auto c:s){
            if(c=='a')a++;
            else if(c=='b')b++;
        }
        cout<<min(a,b)<<"\n";
    }
    return 0;
}
