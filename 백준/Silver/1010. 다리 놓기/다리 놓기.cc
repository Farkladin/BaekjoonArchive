#include "bits/stdc++.h"
using namespace std;
using ll=long long;
ll C[103][103];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    
    C[0][0]=1;
    for(int i=1;i<=100;i++){
        C[i][0]=1;
        for(int j=1;j<=i;j++){
            C[i][j]=C[i-1][j]+C[i-1][j-1];
        }
    }
    
    int T;cin>>T;
    while(T--){
        int N,M;cin>>N>>M;
        cout<<C[M][N]<<"\n";
    }
    return 0;
}
