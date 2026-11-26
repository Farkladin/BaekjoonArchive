#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
constexpr ll upb=1000000001;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,M;cin>>N>>M;
    map<string,ll>price;
    for(int i=1;i<=N;i++){
        string a;ll w;cin>>a>>w;
        price[a]=w;
    }
    vector<pair<string,vector<pair<ll,string> > > >recipe(M);
    for(auto &cur:recipe){
        cin.ignore();
        getline(cin,cur.fi,'=');
        string r;cin>>r;
        r.push_back('+');
        stringstream ss(r);
        
        string tmp;
        while(getline(ss,tmp,'+')){
            cur.se.push_back({tmp[0]-'0',tmp.substr(1)});
        }
    }
    for(int i=1;i<=100;i++){
        for(auto &cur:recipe){
            ll w=0;
            for(auto &x:cur.se){
                if(!price[x.se]){
                    goto skip;
                }
                w=min(upb,w+price[x.se]*x.fi);
            }
            if(!price[cur.fi])price[cur.fi]=w;
            else price[cur.fi]=min(price[cur.fi],w);
            skip:
        }
    }
    cout<<(price["LOVE"]?price["LOVE"]:-1)<<"\n";
    return 0;
}
