#include "bits/stdc++.h"
using namespace std;
int arr[200003];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    
    int n,d;cin>>n>>d;
    for(int i=1;i<=n;i++)cin>>arr[i];
    sort(arr+1,arr+1+n);
    int cnt=0;
    for(int x=1;x<n;){
        if(arr[x+1]-arr[x]<=d){
            cnt++;
            x+=2;
        }else x++;
    }
    cout<<cnt<<"\n";
    return 0;
}
