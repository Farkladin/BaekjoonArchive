#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int T;cin>>T;
    while(T--){
        int H,W,N;cin>>H>>W>>N;
        string tmp=to_string((N-1)/H+1);
        if(tmp.size()==1)tmp="0"+tmp;
        cout<<(N-1)%H+1<<tmp<<"\n";
    }
    return 0;
}
