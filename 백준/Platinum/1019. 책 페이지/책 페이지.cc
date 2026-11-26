#include "bits/stdc++.h"
using namespace std;
using ll=long long;

ll pre[13]={0,1},ans[11];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll t=1;
    for(int i=2;i<=11;i++){
        t*=10;
        pre[i]=t+pre[i-1]*10;
    }
    string N;cin>>N;
    const ll n=(ll)N.size();
    string x=N;
    reverse(N.begin(),N.end());
    
    t=1;
    for(int i=0;i<n;i++){
        ll k=stoll("0"+string(x.end()-i,x.end()));
        ans[N[i]-'0']+=k+1;
        if(i<n-1){
            for(int j=0;j<10;j++){
                ans[j]+=(N[i]-'0')*pre[i];
            }
            for(int j=0;j<N[i]-'0';j++){
                ans[j]+=t;
            }
        }else{
            ans[0]+=(N[i]-'0'-1)*pre[i];
            for(int j=i-1;j>0;j--){
                ans[0]+=pre[j]*9;
            }
            for(int j=1;j<10;j++){
                ans[j]+=(N[i]-'0')*pre[i];
            }
            for(int j=1;j<N[i]-'0';j++){
                ans[j]+=t;
            }
        }
        
        t*=10;
    }
    for(int i=0;i<10;i++)cout<<ans[i]<<" ";
    cout<<"\n";
    return 0;
}
