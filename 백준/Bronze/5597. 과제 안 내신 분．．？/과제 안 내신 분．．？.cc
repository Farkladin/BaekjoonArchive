#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int arr[103];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    for(int i=1;i<=28;i++){
        int x;cin>>x;
        arr[x]=1;
    }
    for(int i=1;i<=30;i++){
        if(!arr[i])cout<<i<<"\n";
    }
    return 0;
}
