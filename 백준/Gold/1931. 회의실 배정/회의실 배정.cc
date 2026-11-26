#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    priority_queue<pair<int,int> >pq;
    int N;cin>>N;
    while(N--){
        int a,b;cin>>a>>b;
        pq.push({-b,-a});
    }
    int t=0,ans=0;
    while(!pq.empty()){
        if(-pq.top().se>=t){
            t=-pq.top().fi;
            ans++;
        }
        pq.pop();
    }
    cout<<ans<<"\n";
    return 0;
}
