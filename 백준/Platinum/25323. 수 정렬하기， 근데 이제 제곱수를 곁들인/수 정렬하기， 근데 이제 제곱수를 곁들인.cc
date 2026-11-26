#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<ll,ll>;
pii arr[500005];
int8_t vis[500005];

bool isSq(ll x){
    double rt=sqrt(x);
    ll a=rt,b=rt+1,c=rt-1;
    if(a*a==x)return true;
    else if(b*b==x)return true;
    else if(c*c==x)return true;
    else return false;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N; cin>>N;
    vector<ll> vec; vec.reserve(N);
    
    for(int i=1; i<=N; ++i){
        cin>>arr[i].first;
        arr[i].second=i;
    }
    sort(arr+1,arr+1+N);
    
    for(int i=1; i<=N; ++i){
        ll u=i;
        vec.clear();
        while(!vis[u]){
            vec.push_back(arr[u].first);
            vis[u]=1;
            u=arr[u].second;
        }
        
        for(int i=1; i<(int)vec.size(); ++i){
            ll x=vec[i-1],y=vec[i];
            ll GCD = gcd(x,y);
            x/=GCD; y/=GCD;
            if(!isSq(x) || !isSq(y)){
                cout<<"NO\n";
                return 0;
            }
        }
    }
    
    cout<<"YES\n";
    
    return 0;
}
