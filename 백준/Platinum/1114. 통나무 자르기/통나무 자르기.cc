#include "bits/stdc++.h"
using namespace std;

int arr[10003],L,K,C;
bool g(int x){
    if(L-arr[K]>x)return false;
    
    int pre=0,cnt=0;
    for(int i=1;i<=K;i++){
        if(arr[i]-pre>x)return false;
        if(arr[i+1]-pre>x){
            cnt++;
            pre=arr[i];
        }
    }
    
    return cnt<=C;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin>>L>>K>>C;
    for(int i=1;i<=K;i++)cin>>arr[i];
    arr[K+1]=L;
    sort(arr+1,arr+1+K);
    
    int le=1,ri=L,mn=2e9;
    while(le<=ri){
        const int mid=(le+ri)>>1;
        if(g(mid)){
            mn=min(mn,mid);
            ri=mid-1;
        }else le=mid+1;
    }
    
    int pre=L,cnt=0;
    for(int i=K;i>0;i--){
        if(pre-arr[i-1]>mn){
            pre=arr[i];
            cnt++;
        }
    }
    if(cnt<C)pre=arr[1];
    cout<<mn<<" "<<pre<<"\n";
    
    return 0;
}
