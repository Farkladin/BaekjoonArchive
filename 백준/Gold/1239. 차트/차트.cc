#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    vector<int>arr(N);
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    int ans=0;
    for(int i=0;i<40320;i++){
        int sum=0,cnt=0;
        for(int l=0,r=0;l<N-1;l++){
            while(sum<50&&r<N-1){
                sum+=arr[r];
                r++;
            }
            if(sum==50)cnt++;
            sum-=arr[l];
        }
        ans=max(ans,cnt);
        next_permutation(arr.begin(),arr.end());
    }
    cout<<ans<<"\n";
    
    return 0;
}
