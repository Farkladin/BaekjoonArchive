#include "bits/stdc++.h"
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    int K=1;
    while(K*K+K+1!=N)K++;
    cout<<K<<"\n";
    return 0;
}
