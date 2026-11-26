#include "bits/stdc++.h"
using namespace std;

int pos[100003];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N; cin>>N;
    for(int i=1; i<=N; ++i){
        int x;cin>>x;
        pos[x]=i;
    }
    
    vector<int>vec;
    for(int j=1;j<=N;++j){
        int x;cin>>x;
        vec.push_back(pos[x]);
    }
    
    vector<int>lis;
    for(auto x:vec){
        if(lis.empty() || lis.back()<x){
            lis.push_back(x);
        }else{
            int pos = int(lower_bound(lis.begin(),lis.end(),x)-lis.begin());
            lis[pos]=x;
        }
    }
    
    cout<<lis.size()<<"\n";
    return 0;
}
