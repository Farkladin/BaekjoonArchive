#include "bits/stdc++.h"
using namespace std;
string ans[15];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ans[0]="-";
    for(int i=1;i<=12;i++){
        ans[i]=ans[i-1]+string(ans[i-1].size(),' ')+ans[i-1];
    }
    int N;
    while(cin>>N){
        cout<<ans[N]<<"\n";
    }
    return 0;
}
