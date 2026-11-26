#include "bits/stdc++.h"
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int A,B,C,D;cin>>A>>B>>C>>D;
    if(C<=D && A+B<=D)cout<<"~.~\n";
    else if(C<=D && A+B>D)cout<<"Walk\n";
    else if(C>D && A+B<=D)cout<<"Shuttle\n";
    else cout<<"T.T\n";
    return 0;
}
