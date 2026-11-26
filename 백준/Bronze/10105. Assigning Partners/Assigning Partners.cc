#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
string arr[33],brr[33];
map<string,string>mp;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    for(int i=1;i<=N;i++)cin>>arr[i];
    for(int j=1;j<=N;j++){
        cin>>brr[j];
        mp[arr[j]]=brr[j];
    }
    bool flag=true;
    for(int i=1;i<=N;i++){
        flag&=mp[brr[i]]==arr[i]&&arr[i]!=brr[i];
    }
    cout<<(flag?"good\n":"bad\n");
    return 0;
}
