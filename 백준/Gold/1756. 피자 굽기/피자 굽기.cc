#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int D,N;cin>>D>>N;
    vector<int>arr(D+3);
    arr[0]=1e9;
    for(int i=1;i<=D;i++){
        cin>>arr[i];
        arr[i]=min(arr[i-1],arr[i]);
    }
    int cur=D;
    for(int i=1;i<=N;i++){
        int x;cin>>x;
        while(cur>=0&&arr[cur]<x)cur--;
        cur=max(-1,cur-1);
    }
    cout<<cur+1<<"\n";
    return 0;
}
