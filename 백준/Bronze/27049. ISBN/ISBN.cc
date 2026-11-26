#include "bits/stdc++.h"
using namespace std;

int main(){
    int sum=0,p=0;
    for(int i=10;i>0;i--){
        char c;cin>>c;
        if(c=='X'){
            sum+=10*i;
        }else if(c=='?'){
            p=i;
        }else{
            sum+=(c-'0')*i;
        }
    }
    sum%=11;
    for(int i=0;i<10;i++){
        if((sum+i*p)%11==0){
            cout<<i<<"\n";
            return 0;
        }
    }
    if(p==1&&(sum+10)%11==0){
        cout<<"X\n";
        return 0;
    }
    cout<<"-1\n";

    return 0;
}
