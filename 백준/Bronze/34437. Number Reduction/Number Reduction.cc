#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    int cnt=0;
    while(N!=1){
        cnt++;
        if(N&1)N+=N*2+1;
        else N>>=1;
    }
    cout<<cnt<<"\n";
    return 0;
}
