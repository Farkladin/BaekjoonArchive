#include "bits/stdc++.h"
using namespace std;
int A[256];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    A['a']=A['i']=A['u']=A['e']=A['o']=1;
    int N;cin>>N;
    int ans=0;
    for(int i=1;i<=N;i++){
        char c;cin>>c;
        ans+=A[c];
    }
    cout<<ans<<"\n";
    return 0;
}
