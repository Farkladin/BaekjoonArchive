#include "bits/stdc++.h"
using namespace std;

int arr[13][13], brr[13][13];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    for(int i=1; i<=10; ++i){
        for(int j=1; j<=10; ++j){
            char c; cin>>c;
            if(c=='#')brr[i][j]=0;
            else brr[i][j]=1;
        }
    }
    
    int ans=1e9;
    
    for(int bit=0; bit<1024; ++bit){
        int cur=0;
        memcpy(arr,brr,sizeof(brr));
        for(int i=0; i<10; ++i){
            if(bit&(1<<i)){
                arr[1][i]^=1;
                arr[1][i+1]^=1;
                arr[1][i+2]^=1;
                arr[2][i+1]^=1;
                ++cur;
            }
        }
        
        for(int i=2; i<=10; ++i){
            for(int j=1; j<=10; ++j){
                if(arr[i-1][j]){
                    arr[i-1][j]^=1;
                    arr[i][j-1]^=1;
                    arr[i][j]^=1;
                    arr[i+1][j]^=1;
                    arr[i][j+1]^=1;
                    ++cur;
                }
            }
        }
        
        int flag=1;
        for(int i=1; i<=10; ++i){
            for(int j=1; j<=10; ++j){
                flag&=arr[i][j]==0;
            }
        }
        
        if(flag) ans=min(ans,cur);
    }
    
    if(ans==1e9) ans=-1;
    cout<<ans<<"\n";
    
    return 0;
}
