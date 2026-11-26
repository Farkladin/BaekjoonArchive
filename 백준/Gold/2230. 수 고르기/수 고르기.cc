#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
int arr[100003];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,M;cin>>N>>M;
    int ans=2e9;
    for(int i=1;i<=N;i++){
        cin>>arr[i];
    }
    sort(arr+1,arr+1+N);
    for(int i=1,j=1;i<=N;i++){
        while(arr[i]-arr[j]>=M){
            ans=min(ans,arr[i]-arr[j]);
            j++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
