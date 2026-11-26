#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;

struct Type{
    ll x,y;
    int id;
    Type(ll x=0, ll y=0, int id=0):x(x),y(y),id(id){}
    
    bool operator<(const Type &rhs) const{
        return x<rhs.x || (x==rhs.x && (y<rhs.y || (y==rhs.y && id<rhs.id)));
    }
};

inline int ccw(const Type &a,const Type &b,const Type &c){
    ll cp=(b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
    if(cp>0)return 1;
    if(cp<0)return -1;
    return 0;
}

bool vis[100003];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    vector<Type>arr(N),hull(N+N);
    for(int i=0;i<N;++i){
        cin>>arr[i].x>>arr[i].y;
        arr[i].id=i;
    }
    sort(arr.begin(),arr.end());
    
    int k=0;
    for(auto &p:arr){
        while(k>=2&&ccw(hull[k-2],hull[k-1],p)<=0)k--;
        hull[k++]=p;
    }
    
    for(int i=N-2,t=k+1;i>=0;i--){
        while(k>=t&&ccw(hull[k-2],hull[k-1],arr[i])<=0) --k;
        hull[k++]=arr[i];
    }
    --k;
    hull.resize(k);
    for(auto &p:hull)vis[p.id]=true;
    
    if(k==N){
        cout<<"2\n";
        cout<<hull[0].id+1<<" "<<hull[2].id+1<<"\n";
    }else{
        cout<<"1\n";
        for(int i=1;i<=N;i++){
            if(!vis[i-1]){
                cout<<i<<"\n";
                break;
            }
        }
    }
    return 0;
}

