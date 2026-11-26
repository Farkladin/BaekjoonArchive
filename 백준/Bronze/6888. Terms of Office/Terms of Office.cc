#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int X,Y;cin>>X>>Y;
    for(int i=X;i<=Y;i+=60){
        cout<<"All positions change in year "<<i<<"\n";
    }
    return 0;
}
