#include "bits/stdc++.h"
using namespace std;

double arr[300003], brr[300003];
int N,K;
bool g(double k){
    for(int i=1; i<=N; ++i){
        brr[i]=brr[i-1]+arr[i]-k;
    }
    
    double x=0;
    for(int i=K; i<=N; ++i){
        x=min(x,brr[i-K]);
        if(brr[i]-x>-1e-9)return true;
    }
    
    return false;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>N>>K;
    for(int i=1; i<=N; ++i) cin>>arr[i];
    double l=0, r=1e6, mid=0;
    while(r-l>1e-9){
        mid = (l+r)*0.5;
        if(g(mid))l=mid;
        else r=mid;
    }
    
    cout<<fixed<<setprecision(6)<<l<<"\n";
    return 0;
}
