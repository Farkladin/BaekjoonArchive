#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    while(1){
        int x,y,z;cin>>x>>y>>z;
        if(x==0&&y==0&&z==0)break;
        if(x>y)swap(x,y);
        if(y>z)swap(y,z);
        cout<<(x*x+y*y==z*z?"right\n":"wrong\n");
    }
    return 0;
}
