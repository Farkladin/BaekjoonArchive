#include "bits/stdc++.h"
using namespace std;

int8_t vis[1000'000];
int arr[5003];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int w,n; cin>>w>>n;
    
    for(int i=1;i<=n;++i)cin>>arr[i];
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            int cur = arr[i]+arr[j];
            if(cur<=w && vis[w-cur]){
                cout<<"YES\n";
                return 0;
            }
        }
        
        for(int j=1;j<i;++j){
            int cur = arr[i]+arr[j];
            if(cur<=w) vis[cur]=1;
        }
    }
    cout<<"NO\n";
    return 0;
}
