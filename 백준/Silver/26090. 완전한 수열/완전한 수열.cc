#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int8_t E[1000003]={1,1};
int arr[503],brr[503];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    for(int i=2;i<=1000;i++){
        if(E[i])continue;
        for(int j=i+i;j<=1000'000;j+=i){
            E[j]=1;
        }
    }
    int N;cin>>N;
    for(int i=1;i<=N;i++){
        cin>>arr[i];
        brr[i]=brr[i-1]+arr[i];
    }
    int ans=0;
    for(int i=1;i<=N;i++){
        for(int j=i+1;j<=N;j++){
            if(!E[j-i+1]&&!E[brr[j]-brr[i-1]]){
                ans++;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}
