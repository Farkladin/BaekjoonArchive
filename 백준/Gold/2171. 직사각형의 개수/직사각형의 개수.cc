#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    set<pair<int,int> >sp;
    vector<pair<int,int> >arr(N+3);
    for(int i=1;i<=N;i++){
        cin>>arr[i].fi>>arr[i].se;
        sp.insert(arr[i]);
    }
    
    int cnt=0;
    for(int i=1;i<=N;i++){
        for(int j=i+1;j<=N;j++){
            if(arr[i].fi!=arr[j].fi&&arr[i].se!=arr[j].se&&sp.find({arr[i].fi,arr[j].se})!=sp.end()&&sp.find({arr[j].fi,arr[i].se})!=sp.end()){
                cnt++;
            }
        }
    }
    cout<<(cnt>>1)<<"\n";
    return 0;
}
