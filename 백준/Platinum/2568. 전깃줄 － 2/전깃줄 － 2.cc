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
    vector<pair<int,int> >vp(N);
    for(int i=0;i<N;i++){
        cin>>vp[i].fi>>vp[i].se;
    }
    sort(vp.begin(),vp.end());
    vector<int>vi={vp.front().se},anc(N+3),idx(N+3);
    anc[0]=-1;
    for(int i=1;i<N;i++){
        if(vi.back()<vp[i].se){
            vi.push_back(vp[i].se);
            idx[vi.size()-1]=i;
            anc[i]=idx[vi.size()-2];
        }else{
            int pos=int(lower_bound(vi.begin(),vi.end(),vp[i].se)-vi.begin());
            vi[pos]=vp[i].se;
            idx[pos]=i;
            if(pos>0)anc[i]=idx[pos-1];
            else anc[i]=-1;
        }
    }
    cout<<N-vi.size()<<"\n";
    vector<int>inLIS(N+3);
    int u=idx[vi.size()-1];
    while(u>=0){
        inLIS[u]=true;
        u=anc[u];
    }
    for(int i=0;i<N;i++){
        if(!inLIS[i])cout<<vp[i].fi<<"\n";
    }
    return 0;
}

