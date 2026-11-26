#include "bits/stdc++.h"
using namespace std;
#define fi first
#define se second
int N;
vector<pair<string,string> >arr;
set<string>fst,snd;
set<pair<string,string> >topic;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int T;cin>>T;
    for(int tc=1;tc<=T;tc++){
        arr.clear();
        cin>>N;
        arr.resize(N+1);
        int ans=0;
        for(int i=0;i<N;i++)cin>>arr[i].fi>>arr[i].se;
        for(int bit=0;bit<(1<<N);bit++){
            fst.clear();
            snd.clear();
            topic.clear();
            for(int j=0;j<N;j++){
                if(bit&(1<<j)){
                    fst.insert(arr[j].fi);
                    snd.insert(arr[j].se);
                    topic.insert(arr[j]);
                }
            }
            bool flag=true;
            for(int j=0;j<N;j++){
                if(!(bit&(1<<j))){
                    flag&=fst.find(arr[j].fi)!=fst.end()&&snd.find(arr[j].se)!=snd.end()&&topic.find(arr[j])==topic.end();
                }
                if(!flag)break;
            }
            if(flag)ans=max(ans,N-__builtin_popcount(bit));
        }
        cout<<format("Case #{:d}: {:d}\n",tc,ans);
    }
    return 0;
}
