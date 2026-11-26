#include "bits/stdc++.h"
using namespace std;
using ll=long long;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m,c;cin>>n>>m>>c;
    deque<pair<int,ll> >maxDq,minDq;
    
    int cnt=0;
    for(int i=1;i<=n;++i){
        ll a; cin>>a;
        if(i>m && maxDq.front().first==i-m)maxDq.pop_front();
        if(i>m && minDq.front().first==i-m)minDq.pop_front();
        
        while(!maxDq.empty() && maxDq.back().second<a)maxDq.pop_back();
        while(!minDq.empty() && minDq.back().second>a)minDq.pop_back();
        maxDq.push_back(pair<int,ll>{i,a});
        minDq.push_back(pair<int,ll>{i,a});
        
        if(i>=m && maxDq.front().second - minDq.front().second <= c){
            ++cnt;
            cout<<i-m+1<<"\n";
        }
    }
    if(cnt==0)cout<<"NONE\n";
    
    return 0;
}
