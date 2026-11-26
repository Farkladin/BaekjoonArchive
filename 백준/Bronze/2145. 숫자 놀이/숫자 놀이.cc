#include "bits/stdc++.h"
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    while(1){
        string s;cin>>s;
        if(s=="0")break;
        int x=0;
        while(s.size()>1){
            for(char c:s)x+=c-'0';
            s=to_string(x);
            x=0;
        }
        cout<<s<<"\n";
    }
    return 0;
}
