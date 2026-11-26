#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int A,B,C,D;cin>>A>>B>>C>>D;
    int t=A*60*60+B*60+C+D;
    C=t%60;t/=60;
    B=t%60;t/=60;
    A=t%24;
    cout<<A<<" "<<B<<" "<<C<<"\n";
    return 0;
}
