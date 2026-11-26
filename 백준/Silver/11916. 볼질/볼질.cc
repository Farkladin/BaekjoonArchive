#include "bits/stdc++.h"
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    int a=0,b=0,c=0,cnt=0,ans=0;
    for(int i=1;i<=N;i++){
        int x;cin>>x;
        if(x==3){
            if(c){
                ans++;
                c=0;
            }
            c=b;
            b=a;
            a=0;
        }
        if(x==1||x==3)cnt++;
        if(cnt==4||x==2){
            cnt=0;
            if(a){
                if(b){
                    if(c){
                        ans++;
                    }
                    c=b;
                }
                b=a;
            }
            a=1;
        }
    }
    
    cout<<ans<<"\n";
    
    return 0;
}
