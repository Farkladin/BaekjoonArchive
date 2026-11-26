#include "bits/stdc++.h"
using namespace std;
int cnt[10003];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    for(int i=1;i<=N;i++){
        int Z;cin>>Z;
        cnt[Z]++;
    }
    for(int i=1;i<N;i++){
        cnt[i]+=cnt[i-1];
        if(cnt[i]>i){
            cout<<i+1<<"\n";
            return 0;
        }
    }
    return 1;
}
