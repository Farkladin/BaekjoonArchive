#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int A[10003];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;cin>>n;
    while(n--){
        string a,b;cin>>a>>b;
        int t=0,s=0;
        for(auto c:a){
            if(c!='.')s=s*10+c-'0';
        }
        for(auto c:b){
            if(c!='.')t=t*10+c-'0';
        }
        int ch4nge=(t-s)/100;
        int v=ch4nge/50,w=ch4nge%50/20,x=ch4nge%50%20/10,y=ch4nge%50%20%10/5,z=ch4nge%50%20%10%5;
        cout<<format("{:d}-$50, {:d}-$20, {:d}-$10, {:d}-$5, {:d}-$1\n",v,w,x,y,z);
    }
    return 0;
}
