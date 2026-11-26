#include "bits/stdc++.h"
using namespace std;
using ll=long long;
map<string,ll>mp;
map<string,pair<ll,ll> >msp;
#define fi first
#define se second
ll A[25];
vector<pair<vector<ll>,string> >vv;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    for(int i=0;i<24;i++)cin>>A[i];
    string s;
    ll cnt1=0,cnt2=0;
    while(cin>>s){
        string a,b;ll c;cin>>a>>b>>c;
        ll t=0;
        for(char c:a){
            if(c!=':')t=t*10+c-'0';
        }
        if(a[0]=='1'&&a[1]=='2')cnt1++;
        if(a[0]=='0'&&a[1]=='1')cnt2++;
        ll tl=(a[6]-'0')*10+a[7]-'0';
        vv.push_back({{t,tl,b=="enter",c},s});
        msp[s]={-1,-1};
    }
    if(cnt1>0&&cnt2>0){
        for(auto &v:vv){
            if(v.fi[0]<12000000){
                v.fi[0]+=12000000;
            }
        }
    }
    sort(vv.begin(),vv.end());
    for(auto &v:vv){
        ll tl=v.fi[1],q=v.fi[2],x=v.fi[3];
        string s=v.se;
        if(q){
            msp[s]={tl,x};
        }else{
            auto &u=msp[s];
            if(u==pair<ll,ll>(-1,-1))continue;
            mp[s]+=A[u.fi]*abs(u.se-x)+100;
            u={-1,-1};
        }
    }
    for(auto x:mp){
        if(!x.se)continue;
        x.se+=200;
        string cent=to_string(x.se%100);
        cent=string(2-cent.size(),'0')+cent;
        cout<<x.fi<<" $"<<x.se/100<<"."<<cent<<"\n";
    }
    return 0;
}
