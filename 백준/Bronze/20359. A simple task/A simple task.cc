#include "bits/stdc++.h"
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;cin>>n;
    int x=1<<20;
    int cnt=19;
    while(x>>=1){
        if(n%x==0){
            cout<<n/x<<" "<<cnt<<"\n";
            return 0;
        }
        cnt--;
    }
    return 0;
}
