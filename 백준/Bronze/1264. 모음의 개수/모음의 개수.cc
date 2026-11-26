#include "bits/stdc++.h"
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while(1){
        string s;
        getline(cin,s);
        if(s=="#")break;
        int cnt=0;
        for(auto c:s){
            if(c<='Z') c+='a'-'A';
            cnt += c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
        }
        cout<<cnt<<"\n";
    }
    
    return 0;
}
