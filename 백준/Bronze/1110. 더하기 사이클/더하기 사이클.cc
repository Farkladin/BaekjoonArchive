#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    int cnt=1,n=N%10*10+(N/10+N%10)%10;
    while(n!=N){
        n=n%10*10+(n/10+n%10)%10;
        cnt++;
    }
    cout<<cnt<<"\n";
    return 0;
}
