#include "bits/stdc++.h"
using namespace std;
int arr[1000003],mx[1000003],mn[1000003];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    vector<int>ans;
    for(int i=1;i<=N;i++){
        cin>>arr[i];
        mx[i]=max(arr[i],mx[i-1]);
    }
    mn[N+1]=1e9;
    for(int i=N;i>0;i--){
        mn[i]=min(arr[i],mn[i+1]);
    }
    for(int i=1;i<=N;i++){
        if(mx[i-1]<=arr[i]&&arr[i]<mn[i+1])ans.push_back(arr[i]);
    }
    cout<<ans.size()<<" ";
    for(int i=0;i<min((int)ans.size(),100);i++)cout<<ans[i]<<" ";
    cout<<"\n";
    return 0;
}
