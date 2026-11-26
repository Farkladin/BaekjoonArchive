#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,k;cin>>N>>k;
    int t=10,d=1;
    for(int i=1;i<=N;i++){
        if(i%t==0){
            t*=10;
            d++;
        }
        if(d<k)k-=d;
        else{
            cout<<to_string(i)[k-1]<<"\n";
            return 0;
        }
    }
    cout<<"-1\n";
    return 0;
}
