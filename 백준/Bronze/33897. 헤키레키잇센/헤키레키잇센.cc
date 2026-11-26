#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    int cnt=0,mx=0,cur=0;
    vector<int>arr(N+3);
    arr[0]=2e9;
    for(int i=1;i<=N;i++){
        cin>>arr[i];
        if(arr[i]>=arr[i-1]){
            cur++;
        }else{
            cnt++;
            mx=max(cur,mx);
            cur=1;
        }
    }
    mx=max(mx,cur);
    cout<<cnt<<" "<<mx<<"\n";
    
    return 0;
}
