#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using lf=double;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;
using ppp=pair<pii,pii>;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    vector<int>arr(N);
    for(int i=0;i<N;i++)cin>>arr[i];
    sort(arr.begin(),arr.end());
    
    int mx=min(N,2);
    for(int i=0;i<N;i++){
        for(int j=i+2;j<N;j++){
            if(arr[i]+arr[i+1]>arr[j])mx=max(mx,j-i+1);
        }
    }
    cout<<mx<<"\n";
    return 0;
}

