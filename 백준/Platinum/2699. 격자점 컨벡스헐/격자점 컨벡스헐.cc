#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;

inline int ccw(const pii &a,const pii &b,const pii &c){
    ll cp=(b.fi-a.fi)*(c.se-a.se)-(b.se-a.se)*(c.fi-a.fi);
    return cp>0?1:(cp<0?-1:0);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int P;cin>>P;
    while(P--){
        int N;cin>>N;
        vector<pii>arr(N),hull(N+N);
        for(auto &p:arr)cin>>p.fi>>p.se;
        sort(arr.begin(),arr.end());
        
        int k=0;
        for(auto &p:arr){
            while(k>=2&&ccw(hull[k-2],hull[k-1],p)<=0)k--;
            hull[k++]=p;
        }
        
        for(int i=N-2,t=k+1;i>=0;i--){
            while(k>=t&&ccw(hull[k-2],hull[k-1],arr[i])<=0)k--;
            hull[k++]=arr[i];
        }
        k--;
        
        cout<<k<<"\n";
        int idx=0;
        ll ymx=-1e9,xmn=1e9;
        for(int i=0;i<k;i++){
            if(ymx<hull[i].se){
                ymx=hull[i].se;
                xmn=hull[i].fi;
                idx=i;
            }else if(ymx==hull[i].se&&xmn>hull[i].fi){
                ymx=hull[i].se;
                xmn=hull[i].fi;
                idx=i;
            }
        }
        
        auto previ=[&k](const int &idx){
            return idx==0?k-1:idx-1;
        };
        
        for(int i=0,j=idx;i<k;i++,j=previ(j)){
            cout<<hull[j].fi<<" "<<hull[j].se<<"\n";
        }
    }
    return 0;
}
