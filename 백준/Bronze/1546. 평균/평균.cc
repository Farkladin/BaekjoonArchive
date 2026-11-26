#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
double arr[103];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cout<<fixed;
    cout.precision(10);
    int N;cin>>N;
    double sum=0,mx=0;
    for(int i=1;i<=N;i++){
        double x;cin>>x;
        sum+=x;
        mx=max(x,mx);
    }
    cout<<sum/mx*100/N<<"\n";
    return 0;
}
