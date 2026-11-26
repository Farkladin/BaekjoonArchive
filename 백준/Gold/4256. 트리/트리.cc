#include "bits/stdc++.h"
using namespace std;
int pre[1003],in[1003];
void f(int x,int s,int e){
    for(int i=s;i<=e;i++){
        if(pre[x]==in[i]){
            f(x+1,s,i-1);
            f(x+i-s+1,i+1,e);
            cout<<pre[x]<<" ";
        }
    }
}
int main(){
    int T;cin>>T;
    while(T--){
        int n;cin>>n;
        for(int i=1;i<=n;i++)cin>>pre[i];
        for(int i=1;i<=n;i++)cin>>in[i];
        f(1,1,n);
        cout<<"\n";
    }
    return 0;
}
