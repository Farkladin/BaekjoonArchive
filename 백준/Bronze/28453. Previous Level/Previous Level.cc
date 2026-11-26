#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    while(N--){
        int M;cin>>M;
        int cur=0;
        if(M>=300)cur=1;
        else if(M>=275)cur=2;
        else if(M>=250)cur=3;
        else cur=4;
        cout<<cur<<" ";
    }
    cout<<"\n";
    return 0;
}
