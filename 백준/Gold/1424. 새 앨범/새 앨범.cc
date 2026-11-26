#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,L,C;cin>>N>>L>>C;
    int n=(C-L)/(L+1)+1;
    if(n%13==0)n--;
    if(N%n==0){
        cout<<N/n<<"\n";
    }else if(n<=N){
        int tmp=N%n;
        if(tmp%13==0&&(n-1)%13==0&&(tmp+2>n))tmp=1;
        else tmp=0;
        cout<<(N+n-1)/n+tmp<<"\n";
    }else{
        cout<<(N%13==0)+1<<"\n";
    }
    return 0;
}
