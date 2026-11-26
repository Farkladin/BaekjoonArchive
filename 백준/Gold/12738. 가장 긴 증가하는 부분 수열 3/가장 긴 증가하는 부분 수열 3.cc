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
    int N;cin>>N;
    vector<int>vi;
    int x;cin>>x;
    vi={x};
    for(int i=2;i<=N;i++){
        cin>>x;
        if(vi.back()<x)vi.push_back(x);
        else{
            auto it=lower_bound(vi.begin(),vi.end(),x);
            (*it)=x;
        }
    }
    cout<<vi.size()<<"\n";
    
    return 0;
}
