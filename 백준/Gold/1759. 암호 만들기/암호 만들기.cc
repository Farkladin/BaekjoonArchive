#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;
char arr[20];
int mp[256];
int L,C;
void f(int i,int j,string s){
    if(i==L){
        int cnt=0;
        for(auto c:s)cnt+=mp[c];
        if(L-cnt>=2&&cnt>=1)cout<<s<<"\n";
        return;
    }
    for(int k=j+1;k<=C;k++){
        f(i+1,k,s+arr[k]);
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin>>L>>C;
    for(int i=1;i<=C;i++)cin>>arr[i];
    sort(arr+1,arr+1+C);
    mp['a']=1;
    mp['e']=1;
    mp['i']=1;
    mp['o']=1;
    mp['u']=1;
    f(0,0,"");
    return 0;
}
