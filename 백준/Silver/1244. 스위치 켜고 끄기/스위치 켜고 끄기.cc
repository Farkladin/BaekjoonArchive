#include "bits/stdc++.h"
using namespace std;

int arr[103];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N; cin>>N;
    for(int i=1; i<=N; ++i) cin>>arr[i];
    int Q; cin>>Q;
    while(Q--){
        int a,b; cin>>a>>b;
        if(a==1){
            for(int i=b; i<=N; i+=b){
                arr[i]^=1;
            }
        }else{
            int l=b, r=b;
            arr[b]^=1;
            while(arr[l-1]==arr[r+1] && l>1 && r<N){
                arr[--l]^=1;
                arr[++r]^=1;
            }
        }
    }
    
    for(int i=1; i<=N; ++i){
        cout<<arr[i]<<" ";
        if(i%20==0)cout<<"\n";
    }
    if(N%20)cout<<"\n";
    
    return 0;
}
