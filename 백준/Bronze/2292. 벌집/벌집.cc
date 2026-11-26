#include "bits/stdc++.h"
using namespace std;

int main() {
    int N; cin>>N;
    if(N==1)cout<<"1\n";
    else{
        --N;
        int a=6, cnt=1;
        while(N>0){
            N-=a;
            ++cnt;
            a+=6;
        }
        cout<<cnt<<"\n";
    }
    return 0;
}
