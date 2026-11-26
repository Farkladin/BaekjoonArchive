#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int arr[100003];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,M;cin>>N>>M;
    while(M--){
        int A,B;cin>>A>>B;
        arr[A]++;
        arr[B]++;
    }
    for(int i=1;i<=N;i++)cout<<arr[i]<<"\n";
    return 0;
}
