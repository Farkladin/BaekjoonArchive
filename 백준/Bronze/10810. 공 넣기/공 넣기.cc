#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int arr[103];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,M;cin>>N>>M;
    while(M--){
        int i,j,k;cin>>i>>j>>k;
        for(int it=i;it<=j;it++){
            arr[it]=k;
        }
    }
    for(int i=1;i<=N;i++)cout<<arr[i]<<" ";
    cout<<"\n";
    return 0;
}
