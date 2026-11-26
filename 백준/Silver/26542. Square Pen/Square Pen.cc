#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
char arr[103][103];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int T;cin>>T;
    for(int tc=1;tc<=T;tc++){
        int N;cin>>N;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++)cin>>arr[i][j];
        }
        int ans=0;
        for(int r=N;r>=0;r--){
            for(int i=1;i<=N-r+1;i++){
                for(int j=1;j<=N-r+1;j++){
                    bool flag=true;
                    for(int x=i;x<i+r;x++){
                        for(int y=j;y<j+r;y++){
                            flag&=arr[x][y]=='.';
                        }
                    }
                    if(flag){
                        ans=r*r;
                        goto skip;
                    }
                }
            }
        }
        skip:
        cout<<ans<<"\n";
    }
    return 0;
}
