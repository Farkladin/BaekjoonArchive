#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
struct point{
    ll x,y;
        point(ll x=0,ll y=0):x(x),y(y){}
    point(initializer_list<ll>il){
        auto it=il.begin();
        x=*it;
        y=*(++it);
    }
    
    bool operator<(const point &ref)const{
        return y<ref.y;
    }
};

inline ll dist(const point &a,const point &b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

inline bool cmp(const point &a,const point &b){
    return a.x<b.x;
}

point arr[500003];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>arr[i].x>>arr[i].y;
    sort(arr+1,arr+1+n,cmp);
    
    set<point>sp({arr[1]});
    ll mn=1e18;
    for(int i=2,j=1;i<=n;i++){
        auto it=sp.upper_bound(point({arr[i].x,arr[i].y-ll(sqrt(mn))-1}));
        if(it!=sp.begin())it--;
        auto jt=sp.upper_bound(point({arr[i].x,arr[i].y+ll(sqrt(mn))+1}));
        for(;it!=jt;it++){
            mn=min(mn,dist(arr[i],*it));
        }
        while(j<=n&&(arr[i].x-arr[j].x)*(arr[i].x-arr[j].x)>=mn)sp.erase(arr[j++]);
        sp.insert(arr[i]);
    }
    cout<<mn<<"\n";
    return 0;
}
