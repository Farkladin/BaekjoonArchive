#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int cnt[10];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int A,B,C;cin>>A>>B>>C;
    A*=B*C;
    while(A){
        cnt[A%10]++;
        A/=10;
    }
    for(int i=0;i<=9;i++)cout<<cnt[i]<<"\n";
    return 0;
}
