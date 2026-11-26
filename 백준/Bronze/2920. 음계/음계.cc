#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    vector<int>arr(8);
    for(int i=0;i<8;i++)cin>>arr[i];
    vector<int>brr=arr,crr=arr;
    sort(brr.begin(),brr.end());
    sort(crr.begin(),crr.end(),greater<int>());
    if(arr==brr)cout<<"ascending\n";
    else if(arr==crr)cout<<"descending\n";
    else cout<<"mixed\n";
    return 0;
}
