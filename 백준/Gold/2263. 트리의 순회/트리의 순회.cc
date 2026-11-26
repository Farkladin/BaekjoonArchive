#include "bits/stdc++.h"
using namespace std;
int in[100003],post[100003];

void f(int x,int s,int e){
    for(int i=s;i<=e;i++){
        if(post[x]==in[i]){
            cout<<post[x]<<" ";
            f(x-(e-i+1),s,i-1);
            f(x-1,i+1,e);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>in[i];
    for(int i=1;i<=n;i++)cin>>post[i];
    
    f(n,1,n);
    cout<<"\n";
    
    return 0;
}
