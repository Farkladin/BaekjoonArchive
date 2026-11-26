#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int arr[103];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,M;cin>>N>>M;
    for(int i=1;i<=N;i++)arr[i]=i;
    while(M--){
        int i,j;cin>>i>>j;
        if(i!=j){
            arr[i]^=arr[j];
            arr[j]^=arr[i];
            arr[i]^=arr[j];
        }
    }
    for(int i=1;i<=N;i++)cout<<arr[i]<<" ";
    cout<<"\n";
    return 0;
}
