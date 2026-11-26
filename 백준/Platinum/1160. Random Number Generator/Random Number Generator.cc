#include "bits/stdc++.h"
using namespace std;
using ll=long long;
ll A[4][4],ret[4][4],res[4][4],m;

void mul(ll a[][4],ll b[][4]){
    for(int i=1;i<=2;i++){
        for(int j=1;j<=2;j++){
            res[i][j]=0;
            for(int k=1;k<=2;k++)res[i][j]=(res[i][j]+(__uint128_t)a[i][k]*b[k][j]%m)%m;
        }
    }
    for(int i=1;i<=2;i++){
        for(int j=1;j<=2;j++)a[i][j]=res[i][j];
    }
}

void po(ll b){
    ret[1][1]=1;
    ret[2][2]=1;
    ret[1][2]=0;
    ret[2][1]=0;
    while(b){
        if(b&1){
            mul(ret,A);
        }
        b>>=1;
        mul(A,A);
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll a,c,X0,n,g;cin>>m>>a>>c>>X0>>n>>g;
    A[1][1]=a;
    A[1][2]=c;
    A[2][1]=0;
    A[2][2]=1;
    
    po(n);
    cout<<ll(((__uint128_t)ret[1][1]*X0%m+ret[1][2])%m)%g<<"\n";
    return 0;
}
