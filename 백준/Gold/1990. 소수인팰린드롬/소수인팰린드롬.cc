#include "bits/stdc++.h"
using namespace std;
using ll=long long;
#define fi first
#define se second
using pii=pair<ll,ll>;
using ppp=pair<pii,pii>;
bool E[10000003];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int a,b;cin>>a>>b;
    for(int i=2;i*i<=100'000'00;i++){
        if(E[i])continue;
        for(int j=i+i;j<=100'000'00;j+=i)E[j]=true;
    }
    for(auto cur:{2,3,5,7,11}){
        if(a<=cur&&cur<=b){
            cout<<cur<<"\n";
        }
    }
    vector<ll>ans;
    for(int i=10;i<10000;i++){
        int cur=i,tmp=i/10;
        while(tmp){
            cur=cur*10+tmp%10;
            tmp/=10;
        }
        if(a<=cur&&cur<=b){
            if(!E[cur])cout<<cur<<"\n";
        }
    }
    for(auto a:ans)cout<<a<<"\n";
    cout<<"-1\n";
    return 0;
}
