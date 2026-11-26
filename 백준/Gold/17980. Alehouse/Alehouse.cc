#include "bits/stdc++.h"
using namespace std;
#define fi first
#define se second
int arr[100003],brr[100003];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>arr[i]>>brr[i];
    }
    sort(arr+1,arr+1+n);
    sort(brr+1,brr+1+n);
    int ans=0;
    for(int i=1,j=0;i<=n;i++){
        while(j+1<=n&&arr[j+1]<=brr[i]+k)j++;
        ans=max(ans,j-i+1);
    }
    cout<<ans<<"\n";
    return 0;
}
