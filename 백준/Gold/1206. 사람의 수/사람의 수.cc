#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int arr[53];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    for(int i=1;i<=N;i++){
        string s;cin>>s;
        int x=0;
        for(char c:s){
            if(c=='.')continue;
            x=x*10+c-'0';
        }
        arr[i]=x;
    }
    for(int i=1;i<=1000;i++){
        for(int j=1;j<=50;j++){
            if(arr[j]*i%1000==0){
                continue;
            }else{
                int tmp=arr[j]*i+1000;
                tmp-=tmp%1000;
                if(tmp/i==arr[j]){
                    continue;
                }
            }
            goto skip;
        }
        cout<<i<<"\n";
        return 0;
        skip:
    }
    return 1;
}
