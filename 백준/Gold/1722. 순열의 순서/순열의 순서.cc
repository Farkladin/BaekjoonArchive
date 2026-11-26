#include "bits/stdc++.h"
using namespace std;
using ll=long long;
ll facto[23]={1};
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    for(int i=1;i<=20;i++)facto[i]=facto[i-1]*i;
    int N,q;cin>>N>>q;
    if(q==1){
        ll x;cin>>x;
        vector<int>arr(N);
        for(int n=N-1;n>=0;n--){
            ll tmp=(x+facto[n]-1)/facto[n];
            for(int i=0,j=0;i<N;i++){
                if(!arr[i])j++;
                if(j==tmp){
                    arr[i]=1;
                    cout<<i+1<<" ";
                    goto done;
                }
            }
            done:
            x-=(tmp-1)*facto[n];
        }
        cout<<"\n";
    }else{
        ll ans=0;
        vector<int>arr(N+1);
        for(int i=N-1;i>=0;i--){
            ll x;cin>>x;
            ll cnt=0;
            for(int j=1;j<=x;j++){
                if(!arr[j])cnt++;
            }
            arr[x]=1;
            ans+=(cnt-1)*facto[i];
        }
        cout<<ans+1<<"\n";
    }
    return 0;
}
