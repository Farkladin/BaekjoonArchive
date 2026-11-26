#include "bits/stdc++.h"
using namespace std;
using ll=long long;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    string T;cin>>T;
    string S="@";
    for(auto c:T){
        S.push_back(c);
        S.push_back('@');
    }
    int n=(int)S.size(),r=0,p=0;
    vector<int>arr(n+3);
    ll ans=0;
    for(int i=0;i<n;i++){
        if(i<=r)arr[i]=min(arr[2*p-i],r-i);else arr[i]=0;
        while(i-arr[i]-1>=0&&i+arr[i]+1<n&&S[i-arr[i]-1]==S[i+arr[i]+1])arr[i]++;
        if(arr[i]+i>r){
            r=arr[i]+i;
            p=i;
        }
        if(arr[i]&1){
            ans+=(arr[i]+1)>>1;
        }else{
            ans+=arr[i]>>1;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
