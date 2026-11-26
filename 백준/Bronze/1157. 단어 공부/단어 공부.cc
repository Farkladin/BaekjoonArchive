#include "bits/stdc++.h"
using namespace std;
int cnt[256];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    string s;cin>>s;
    for(auto &c:s){
        if(c>'Z')c-='a'-'A';
        cnt[c]++;
    }
    int mx=0;
    char ch='?';
    for(char i='A';i<='Z';i++){
        if(cnt[i]>mx){
            mx=cnt[i];
            ch=i;
        }else if(mx==cnt[i]){
            ch='?';
        }
    }
    cout<<ch<<"\n";
    return 0;
}
