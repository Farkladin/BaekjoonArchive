#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int D[100003];
vector<pair<int,int> >ans;
void f(int n,int x,int y,int z){
    if(n==0)return;
    f(n-1,x,z,y);
    cout<<x<<" "<<y<<"\n";
    f(n-1,z,y,x);
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    cout<<(1<<N)-1<<"\n";
    f(N,1,3,2);
    return 0;
}
