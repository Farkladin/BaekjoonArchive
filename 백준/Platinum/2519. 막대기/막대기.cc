#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using lf=double;
using ll=long long;
using pii=pair<ll,ll>;
using ppp=pair<pii,pii>;

inline int ccw(const pii &a,const pii &b,const pii &c){
    ll cp=(b.fi-a.fi)*(c.se-a.se)-(b.se-a.se)*(c.fi-a.fi);
    return cp>0?1:(cp<0?-1:0);
}

bool lsi(ppp a,ppp b){
    ll ab=ccw(a.fi,a.se,b.fi)*ccw(a.fi,a.se,b.se),ba=ccw(b.fi,b.se,a.fi)*ccw(b.fi,b.se,a.se);
    if(ab==0&&ba==0){
        if(a.fi>a.se)swap(a.fi,a.se);
        if(b.fi>b.se)swap(b.fi,b.se);
        return b.fi<=a.se&&a.fi<=b.se;
    }
    return ab<=0&&ba<=0;
}

vector<vector<int> >G,GT,SCC;
vector<bool>vis;
stack<int>stk;
vector<int>cn;
int N;

void DFS(int x,const bool T){
    vector<int>&g=T?GT[x]:G[x];
    for(int y:g){
        if(vis[y])continue;
        vis[y]=true;
        if(T){
            SCC.back().push_back(y);
            cn[y]=(int)SCC.size();
        }
        DFS(y,T);
    }
    if(!T)stk.push(x);
}

inline int NOT(const int &x){
    return x<=3*N?x+3*N:x-3*N;
}

void addOR(const int &x,const int &y){
    G[NOT(x)].push_back(y);
    G[NOT(y)].push_back(x);
    GT[y].push_back(NOT(x));
    GT[x].push_back(NOT(y));
}

ppp arr[6003];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin>>N;
    G.resize(6*N+2);GT.resize(6*N+2);
    cn.resize(6*N+2);
    for(int i=1;i<=3*N;i+=3){
        int x(i),y(i+1),z(i+2);
        addOR(x,y);
        addOR(y,z);
        addOR(z,x);
    }
    for(int i=1;i<=N*3;i++){
        cin>>arr[i].fi.fi>>arr[i].fi.se>>arr[i].se.fi>>arr[i].se.se;
        for(int j=1;j<i;j++){
            if(lsi(arr[i],arr[j])){
                addOR(NOT(i),NOT(j));
            }
        }
    }
    
    vis.resize(6*N+2);
    for(int x=1;x<=6*N;x++){
        if(vis[x])continue;
        vis[x]=true;
        DFS(x,false);
    }
    
    fill(vis.begin(),vis.end(),false);
    while(!stk.empty()){
        int x=stk.top();stk.pop();
        if(vis[x])continue;
        vis[x]=true;
        SCC.push_back({x});
        cn[x]=(int)SCC.size();
        DFS(x,true);
    }
    bool ans=true;
    for(int i=1;i<=3*N;i++){
        ans&=(cn[i]!=cn[i+3*N]);
    }
    
    if(ans){
        vector<int>tmp;
        for(int i=1;i<=3*N;i++){
            if(cn[i]<=cn[i+3*N])tmp.push_back(i);
        }
        cout<<tmp.size()<<"\n";
        if(!tmp.empty()){
            for(auto x:tmp)cout<<x<<" ";
            cout<<"\n";
        }
    }else cout<<"-1\n";
    return 0;
}
