#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
constexpr int zero=100;
int cnt[203];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    for(int i=1;i<=N;i++){
        int x;cin>>x;
        cnt[x+zero]++;
    }
    int v;cin>>v;
    cout<<cnt[v+zero]<<"\n";
    return 0;
}
