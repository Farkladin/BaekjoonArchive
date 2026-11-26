#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    int ans=1e9;
    for(int i=0;i*5<=N;i++){
        if((N-i*5)%3==0){
            ans=min(ans,i+(N-i*5)/3);
        }
    }
    if(ans==1e9)ans=-1;
    cout<<ans<<"\n";
}
