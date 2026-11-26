#include "bits/stdc++.h"
using namespace std;
using ll = long long;

constexpr int sz=1<<22;
int seg[(sz<<1)|3];

int sfind(int x){
    int s=1,e=sz,pos=1;
    while(s<e){
        const int mid=(s+e)>>1;
        if(seg[pos*2]<x){
            x-=seg[pos*2];
            s=mid+1;
            pos=pos*2+1;
        }else{
            e=mid;
            pos*=2;
        }
    }
    return s;
}

void add(ll p,ll dw){
    p+=sz-1;
    seg[p]+=dw;
    while(p>>=1){
        seg[p]=seg[p*2]+seg[p*2+1];
    }
}

int arr[4000003],brr[4000003];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int N;cin>>N;
    int hN=N>>1;
    for(int i=1;i<=N;++i)add(i,1);
    for(int i=1;i<=hN;++i)cin>>arr[i];
    for(int i=1;i<=hN;++i)cin>>brr[i];
    vector<int>team1,team2;
    for(int i=1;i<=hN;++i){
        int p;
        
        p=sfind(arr[i]);
        team1.push_back(p);
        add(p,-1);
        
        p=sfind(brr[i]);
        team2.push_back(p);
        add(p,-1);
    }
    
    for(auto x:team1)cout<<x<<" ";
    cout<<"\n";
    for(auto x:team2)cout<<x<<" ";
    cout<<"\n";
    return 0;
}
