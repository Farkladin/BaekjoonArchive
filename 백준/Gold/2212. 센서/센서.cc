#include "bits/stdc++.h"
using namespace std;
using ll=long long;
#define fi first
#define se second

int arr[10003];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,K;cin>>N>>K;
    for(int i=1;i<=N;i++)cin>>arr[i];
    sort(arr+1,arr+1+N);
    priority_queue<int>pq;
    for(int i=2;i<=N;i++){
        pq.push(arr[i-1]-arr[i]);
        if(pq.size()>=K)pq.pop();
    }
    int ans=arr[N]-arr[1];
    while(!pq.empty()){
        ans+=pq.top();
        pq.pop();
    }
    cout<<ans<<"\n";
    return 0;
}
