#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    string S="001";
    while(S.size()<=100000){
        string T(S.rbegin(),S.rend());
        for(auto &c:T){
            if(c=='1')c='0';
            else c='1';
        }
        S=S+"0"+T;
    }
    int T;cin>>T;
    for(int tc=1;tc<=T;tc++){
        int K;cin>>K;
        cout<<"Case #"<<tc<<": "<<S[K-1]<<"\n";
    }
    return 0;
}
