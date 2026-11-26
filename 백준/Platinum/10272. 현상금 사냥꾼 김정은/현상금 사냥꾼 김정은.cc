#include "bits/stdc++.h"
using namespace std;

struct Type{
    double x,y;
    Type(double x=0,double y=0):x(x),y(y){}
    
    Type operator-(const Type &rhs) const{
        return Type(x-rhs.x,y-rhs.y);
    }
    
}arr[555];
double dp[555][555];

inline double ABS(const Type a){
    return sqrt(a.x*a.x+a.y*a.y);
}

inline double dist(const int &a, const int &b){
    return ABS(arr[a]-arr[b]);
}

int N;
int8_t vis[555][555];
double f(int i,int j){
    double &ret=dp[i][j];
    if(vis[i][j])return ret;
    vis[i][j]=1;
    int nxt=max(i,j)+1;
    if(nxt==N)ret=dist(i,nxt)+dist(nxt,j);
    else ret=min(f(nxt,j)+dist(i,nxt), f(i,nxt)+dist(j,nxt));
    return ret;
}

void solve(){
    cin>>N;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=N;++i){
        cin>>arr[i].x>>arr[i].y;
    }
    cout<<f(1,1)<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout<<fixed<<setprecision(2);
    int T;cin>>T;
    while(T--)solve();
    return 0;
}
