#include "bits/stdc++.h"
using namespace std;
int arr[50003];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    int sum=0;
    for(int i=1;i<=N;i++){
        cin>>arr[i];
        sum+=arr[i];
        arr[i]+=arr[i-1];
    }
    int ans=0;
    for(int l=1,r=1;r<=N;r++){
        while(sum-arr[r]+arr[l]<arr[r]-arr[l]){
            ans=max(ans,min(sum-arr[r]+arr[l],arr[r]-arr[l]));
            l++;
        }
        ans=max(ans,min(sum-arr[r]+arr[l],arr[r]-arr[l]));
    }
    cout<<ans<<"\n";
    return 0;
}
