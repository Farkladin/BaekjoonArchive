#include "bits/stdc++.h"
using namespace std;

int fib[1000003], sz[1000003];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int Q, M; cin>>Q>>M;
    fib[1]=fib[2]=1;
    sz[1]=sz[2]=1;
    int idx=0, k=2;
    for(int i=3; i<=1000000; ++i){
        fib[i]=(fib[i-1]+fib[i-2])%M;
        sz[i]=(int)to_string(fib[i]).size();
        if(fib[i]==1 && fib[i-1]==1){
            idx=i;
            --k;
            break;
        }
        k+=sz[i];
    }
    
    while(Q--){
        int64_t N; cin>>N;
        N = (N-1)%k+1;
        for(int i=1; i<=k; ++i){
            if(N>sz[i])N-=sz[i];
            else{
                cout<<to_string(fib[i]).at(N-1)<<"\n";
                break;
            }
        }
    }
    
    return 0;
}
