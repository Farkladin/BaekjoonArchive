#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    while(N--){
        int X;cin>>X;
        char c;cin>>c;
        int a=0,b;
        if(c=='!')a=10;
        else a=c-'0';
        while(X--){
            char oper,num;cin>>oper>>num;
            if(num=='!')b=10;
            else b=num-'0';
            a+=b;
            if(a>10)a=10;
        }
        if(a<10)cout<<a<<"\n";
        else cout<<"!\n";
    }
    return 0;
}
