#include "bits/stdc++.h"
using namespace std;
using ll=long long;
int arr[1003];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    int cnt=0,t=1000;
    for(int i=1;i<=N;i++){
        string s;
        long long x;
        cin>>s>>x;
        if(x>1000)cnt++;
        else arr[x]++;
        if(s=="jinju")t=(int)x;
    }
    for(int i=t+1;i<=1000;i++)cnt+=arr[i];
    cout<<t<<"\n"<<cnt<<"\n";
    return 0;
}
