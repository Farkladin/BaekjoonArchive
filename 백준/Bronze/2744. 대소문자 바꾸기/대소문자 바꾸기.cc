#include "bits/stdc++.h"
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    string s;cin>>s;
    for(char &c:s){
        if(c>'Z')c-='a'-'A';
        else c-='A'-'a';
    }
    cout<<s<<"\n";
    return 0;
}
