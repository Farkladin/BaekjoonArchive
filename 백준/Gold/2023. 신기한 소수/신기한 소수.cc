#include "bits/stdc++.h"
using namespace std;
using ll=long long;
bool g(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0)return false;
    }
    return true;
}

int N;
void f(int n,int i){
    if(i==N){
        cout<<n<<"\n";
        return;
    }
    for(int j=1;j<=9;j+=2){
        if(g(n*10+j))f(n*10+j,i+1);
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin>>N;
    f(2,1);
    f(3,1);
    f(5,1);
    f(7,1);
    return 0;
}
