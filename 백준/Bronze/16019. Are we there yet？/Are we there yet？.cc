#include "bits/stdc++.h"
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    
    int a,b,c,d;cin>>a>>b>>c>>d;
    cout<<"0 "<<a<<" "<<a+b<<" "<<a+b+c<<" "<<a+b+c+d<<"\n"<<a<<" 0 "<<b<<" "<<b+c<<" "<<b+c+d<<"\n"<<a+b<<" "<<b<<" 0 "<<c<<" "<<c+d<<"\n"<<a+b+c<<" "<<b+c<<" "<<c<<" 0 "<<d<<"\n"<<a+b+c+d<<" "<<b+c+d<<" "<<c+d<<" "<<d<<" 0\n";
    return 0;
}
