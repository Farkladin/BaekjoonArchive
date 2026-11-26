#include "bits/stdc++.h"
using namespace std;
int arr[103];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,M;cin>>N>>M;
    int ans=0;
    for(int i=1;i<=N;i++){
        cin>>arr[i];
        for(int j=1;j<i;j++){
            for(int k=1;k<j;k++){
                int cur=arr[i]+arr[j]+arr[k];
                if(cur<=M){
                    ans=max(ans,cur);
                }
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}
