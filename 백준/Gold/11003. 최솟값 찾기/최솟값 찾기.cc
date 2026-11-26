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
    int N,L;cin>>N>>L;
    vector<int>dq(N+3),arr(N+3);
    for(int i=1,l=1,r=1;i<=N;i++){
        cin>>arr[i];
        if(l<r&&dq[l]==i-L)l++;
        while(l<r&&arr[dq[r-1]]>arr[i])r--;
        dq[r++]=i;
        cout<<arr[dq[l]]<<" ";
    }
    cout<<"\n";
    return 0;
}
