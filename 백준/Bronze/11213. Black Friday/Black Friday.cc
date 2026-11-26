#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int cnt[103],idx[103];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        cnt[x]++;
        idx[x]=i;
    }
    for(int i=6;i>0;i--){
        if(cnt[i]==1){
            cout<<idx[i]<<"\n";
            return 0;
        }
    }
    cout<<"none\n";
    return 0;
}
