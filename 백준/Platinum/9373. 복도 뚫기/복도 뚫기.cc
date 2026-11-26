#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
using tri=array<ll,3>;
using pii=pair<ll,ll>;
int pos[1005];
tri arr[1005];

inline ll dist(const tri &a,const tri &b){
    return (a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]);
}

int find(int x){
    int z(x);
    while(z!=pos[z])z=pos[z];
    while(x!=pos[x]){
        int tmp=x;
        x=pos[x];
        pos[tmp]=z;
    }
    return z;
}

void merge(int x,int y){
    x=find(x);
    while(y!=pos[y]){
        int tmp=y;
        y=pos[y];
        pos[tmp]=x;
    }
    pos[y]=x;
}

void solve(){
    ll w;cin>>w;
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    vector<pair<double,pii> >E;
    for(int i=1;i<=n+2;i++)pos[i]=i;
    for(int i=1;i<=n;i++){
        E.push_back({arr[i][0]-arr[i][2],{i,n+1}});
        E.push_back({w-arr[i][0]-arr[i][2],{i,n+2}});
        for(int j=i+1;j<=n;j++){
            E.push_back({sqrt(dist(arr[i],arr[j]))-arr[i][2]-arr[j][2],{i,j}});
        }
    }
    E.push_back({w,{n+1,n+2}});
    sort(E.begin(),E.end());
    double mx=0;
    for(auto &t:E){
        int x=(int)t.se.fi,y=(int)t.se.se;
        if(find(x)!=find(y)){
            merge(x,y);
            mx=max(mx,t.fi);
            if(find(n+1)==find(n+2))break;
        }
    }
    cout<<fixed<<setprecision(6)<<mx*0.5<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int T;cin>>T;
    while(T--)solve();
    return 0;
}
