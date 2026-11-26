#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    vector<int>ge,le;
    for(int i=0;i<N;i++){
        int x;cin>>x;
        if(x>0)ge.push_back(x);
        else le.push_back(-x);
    }
    sort(ge.begin(),ge.end());
    sort(le.begin(),le.end());
    vector<int>ans;
    for(int i=0;i<=N;i++){
        auto it=upper_bound(ge.begin(),ge.end(),i);
        auto jt=lower_bound(le.begin(),le.end(),i);
        int k=int(ge.end()-it+jt-le.begin());
        if(k==i)ans.push_back(i);
    }
    cout<<ans.size()<<"\n";
    for(auto a:ans)cout<<a<<" ";
    cout<<"\n";
    return 0;
}
