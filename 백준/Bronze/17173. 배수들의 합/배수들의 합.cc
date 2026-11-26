#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int K[1003];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,M;cin>>N>>M;
    for(int i=1;i<=M;i++)cin>>K[i];
    int sum=0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(i%K[j]==0){
                sum+=i;
                goto skip;
            }
        }
        skip:
    }
    cout<<sum<<"\n";
    return 0;
}
