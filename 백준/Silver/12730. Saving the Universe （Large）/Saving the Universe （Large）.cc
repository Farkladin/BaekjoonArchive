#include "bits/stdc++.h"
#include <format>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    for(int tc=1;tc<=N;tc++){
        int S;cin>>S;
        cin.ignore();
        vector<string>vs(S+2);
        for(int i=1;i<=S;i++){
            getline(cin,vs[i]);
        }
        int ans=1e9;
        set<pair<int,int> >vp;
        int Q;cin>>Q;
        cin.ignore();
        if(Q==0){
            ans=1;
        }
        vector<string>arr(Q+3);
        for(int i=1;i<=Q;i++){
            string s;
            getline(cin,arr[i]);
        }
        for(int i=1;i<=S;i++){
            int cnt=0;
            for(int j=1;j<=Q+1;j++){
                if(vs[i]!=arr[j]&&j<=Q)cnt++;
                else{
                    if(cnt){
                        vp.insert({j-cnt,j-1});
                        cnt=0;
                    }
                }
            }
        }
        priority_queue<pair<int,int> >pq;pq.push({0,0});
        for(auto &p:vp){
            while(!pq.empty()&&-pq.top().second+1<p.first)pq.pop();
            pq.push({pq.top().first-1,-p.second});
            if(p.second==Q)ans=min(ans,-pq.top().first+1);
        }
        cout<<format("Case #{:d}: {:d}\n",tc,ans-1);
    }
    return 0;
}
