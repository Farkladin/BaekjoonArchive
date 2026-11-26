#include "bits/stdc++.h"
using namespace std;

int arr[1000003], ans[1000003];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N; cin>>N;
    int cnt=0, st=0;
    for(int i=1; i<=N; ++i){
        char c; cin>>c;
        arr[i]= c=='O';
        arr[i+N]=arr[i];
        if(arr[i] && !st) st=i;
    }
    
    for(int i=st; i<=st+N; ++i){
        if(!arr[i]) ++cnt;
        else{
            ans[i]=1;
            if(cnt&1){
                for(int j=i-cnt; j<i-(cnt>>1)-1; ++j){
                    ans[j>N?j-N:j]=1;
                }
                for(int j=i-(cnt>>1); j<i; ++j){
                    ans[j>N?j-N:j]=0;
                }
            }else if(cnt){
                cout<<"NO\n";
                return 0;
            }
            cnt=0;
        }
    }
    
    cout<<"YES\n";
    for(int i=1; i<=N; ++i) cout<<(ans[i]?"+":"-");
    cout<<"\n";
    
    return 0;
}
