#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
char arr[103][103];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++)cin>>arr[i][j];
    }
    bool flag=true;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            flag&=arr[i][j]==arr[j][i];
        }
    }
    cout<<(flag?"YES\n":"NO\n");
    return 0;
}
