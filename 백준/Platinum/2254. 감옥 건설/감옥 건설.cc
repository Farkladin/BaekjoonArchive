#include "bits/stdc++.h"
using namespace std;
using ll=long long;
#define fi first
#define se second
using pii=pair<ll,ll>;
using ppp=pair<pii,pii>;

inline int ccw(const pii &a,const pii &b,const pii &c){
    ll cp=(b.fi-a.fi)*(c.se-a.se)-(b.se-a.se)*(c.fi-a.fi);
    return cp>0?1:(cp<0?-1:0);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,Px,Py;cin>>N>>Px>>Py;
    set<pii>sp;
    sp.insert({Px,Py});
    for(int i=0;i<N;i++){
        int x,y;cin>>x>>y;
        sp.insert({x,y});
    }
    int ans=0;
    while(sp.size()>=3){
        const int n=(int)sp.size();
        vector<pii>arr(sp.begin(),sp.end()),hull(n+n);
        
        int k=0;
        for(auto &p:arr){
            while(k>=2&&ccw(hull[k-2],hull[k-1],p)<=0)k--;
            hull[k++]=p;
        }
        
        for(int i=n-2,t=k+1;i>=0;i--){
            while(k>=t&&ccw(hull[k-2],hull[k-1],arr[i])<=0)k--;
            hull[k++]=arr[i];
        }
        k--;
        
        for(int i=0;i<k;i++){
            sp.erase(hull[i]);
        }
        
        if(sp.find({Px,Py})==sp.end()){
            break;
        }
        ans++;
    }
    cout<<ans<<"\n";
    
    return 0;
}
