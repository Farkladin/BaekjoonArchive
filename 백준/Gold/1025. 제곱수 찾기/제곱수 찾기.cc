#include "bits/stdc++.h"
using namespace std;
using ll=long long;
char arr[12][12];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,M;cin>>N>>M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++)cin>>arr[i][j];
    }
    int ans=-1;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            for(int x=-N;x<=N;x++){
                for(int y=-M;y<=M;y++){
                    int cur=0,a=i,b=j;
                    
                    if(x==0&&y==0){
                        cur=arr[i][j]-'0';
                        goto skip;
                    }
                    
                    while(a<=N&&b<=M&&a>=1&&b>=1){
                        cur=cur*10+arr[a][b]-'0';
                        a+=x;
                        b+=y;
                        int t=sqrt(cur)+1e-9;
                        if(t*t==cur)ans=max(ans,cur);
                    }
                    skip:
                    int t=sqrt(cur)+1e-9;
                    if(t*t==cur)ans=max(ans,cur);
                }
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}
