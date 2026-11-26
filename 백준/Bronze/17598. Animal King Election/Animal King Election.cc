#include "bits/stdc++.h"
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int a=0,b=0;
    for(int i=0;i<9;i++){
        string s;cin>>s;
        if(s=="Lion")a++;
        else b++;
    }
    cout<<(a>b?"Lion\n":"Tiger\n");
    return 0;
}
