#include "bits/stdc++.h"
using namespace std;

int arr[10003];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;cin>>n;
    for(int i=1;i<=n;++i){
        cin>>arr[i];
    }
    sort(arr+1,arr+1+n);
    
    bool ans=true;
    int k=0;
    for(int i=1;i<=n;++i){
        k+=arr[i];
        if(k<(i*(i-1)>>1))ans=false;
    }
    ans&= k==((n*(n-1))>>1);
    cout<<(ans?"1\n":"-1\n");
    return 0;
}
