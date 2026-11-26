#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int D[100003];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,K;cin>>N>>K;
    for(int i=1;i<=N;i++){
        int W,V;cin>>W>>V;
        for(int i=K-W;i>0;i--){
            if(D[i])D[i+W]=max(D[i+W],V+D[i]);
        }
        D[W]=max(D[W],V);
    }
    int ans=0;
    for(int i=1;i<=K;i++)ans=max(ans,D[i]);
    cout<<ans<<"\n";
    return 0;
}
