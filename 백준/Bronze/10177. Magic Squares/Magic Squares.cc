#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int arr[10][10];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;cin>>n;
    while(n--){
        int m;cin>>m;
        int sum=0,cur;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++)cin>>arr[i][j];
            sum+=arr[i][1];
        }
        
        for(int i=1;i<=m;i++){
            cur=0;
            for(int j=1;j<=m;j++){
                cur+=arr[i][j];
            }
            if(sum!=cur)goto fail;
        }
        
        for(int j=1;j<=m;j++){
            cur=0;
            for(int i=1;i<=m;i++){
                cur+=arr[i][j];
            }
            if(sum!=cur)goto fail;
        }
        
        cur=0;
        for(int i=1;i<=m;i++){
            cur+=arr[i][i];
        }
        if(sum!=cur)goto fail;
        
        cur=0;
        for(int i=1;i<=m;i++){
            cur+=arr[i][m-i+1];
        }
        if(sum!=cur)goto fail;
        
        cout<<"Magic square of size "<<m<<"\n";
        continue;
        
        fail:
        cout<<"Not a magic square\n";
    }
    return 0;
}
