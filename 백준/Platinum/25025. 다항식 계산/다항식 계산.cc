#include "bits/stdc++.h"
using namespace std;

int arr[1003];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,P;cin>>N>>P;
    for(int i=N;i>0;--i){
        int a;cin>>a;
        arr[i%(P-1)]=(arr[i%(P-1)]+a)%P;
    }
    int a0;cin>>a0;
    cout<<a0%P<<"\n";
    arr[0]=(arr[0]+a0)%P;
    for(int i=1;i<P;++i){
        int k=1, ans=0;
        for(int j=0;j<P-1;j++){
            ans=(ans+arr[j]*k%P)%P;
            k=k*i%P;
        }
        cout<<ans<<"\n";
    }
    
    return 0;
}
