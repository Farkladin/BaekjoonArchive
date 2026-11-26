#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using lf=double;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;
using ppp=pair<pii,pii>;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    set<int>si;
    int N;cin>>N;
    vector<int>arr(N+3);
    for(int i=1;i<=N;i++){
        cin>>arr[i];
        si.insert(arr[i]);
    }
    pair<int,pair<int,int> >ans={2e9+1,{0,0}};
    for(int i=1;i<=N;i++){
        auto it=si.lower_bound(-arr[i]),jt=it;
        if(jt!=si.begin())jt--;
        int t1=abs(*it+arr[i]),t2=abs(*jt+arr[i]);
        if(t1<ans.fi&&*it!=arr[i]&&it!=si.end()){
            ans={t1,{min(arr[i],*it),max(arr[i],*it)}};
        }
        if(t2<ans.fi&&*jt!=arr[i]){
            ans={t2,{min(arr[i],*jt),max(arr[i],*jt)}};
        }
    }
    cout<<ans.se.fi<<" "<<ans.se.se<<"\n";
    return 0;
}

