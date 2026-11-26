#include "bits/stdc++.h"
using namespace std;
constexpr int n=1<<20;
int arr[n|3],tmp[n|3];
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    fill(arr,arr+n,2e9);
    for(int i=0;i<N;i++)cin>>arr[i];
    ll ans=0;
    for(int k=2;k<=n;k<<=1){
        for(int j=0;j<n;j+=k){
            {
                const int t=k>>1;
                int i1=j,i2=j+t,i=j;
                while(i<j+k){
                    if(i1>=j+t)goto useRight;
                    if(i2>=j+k)goto useLeft;
                    if(arr[i1]<=arr[i2])goto useLeft;
                    else goto useRight;
                    
                    useLeft:{
                        tmp[i++]=arr[i1++];
                        continue;
                    }
                    useRight:{
                        tmp[i++]=arr[i2++];
                        ans+=j+t-i1;
                        continue;
                    }
                }
            }
            for(int i=j;i<j+k;i++){
                arr[i]=tmp[i];
            }
        }
    }
    
    cout<<ans<<"\n";
    return 0;
}
