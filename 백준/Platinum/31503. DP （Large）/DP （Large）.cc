#include "bits/stdc++.h"
using namespace std;
using ll=long long;

int arr[300003],brr[300003];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,Q; cin>>N>>Q;
    
    vector<ll>vec(N);
    for(auto &x:vec){
        cin>>x;
    }
    
    vector<ll>lis;
    for(int i=0; i<N; ++i){
        ll x=vec[i];
        if(lis.empty() || lis.back()<x){
            lis.push_back(x);
            arr[i]=(int)lis.size();
        }else{
            auto it = lower_bound(lis.begin(),lis.end(),x);
            *it = x;
            arr[i]=int(it-lis.begin())+1;
        }
    }
    
    lis.clear();
    vec=vector<ll>(vec.rbegin(),vec.rend());
    for(int i=0; i<N; ++i){
        ll x=-vec[i];
        if(lis.empty() || lis.back()<x){
            lis.push_back(x);
            brr[i]=(int)lis.size();
        }else{
            auto it = lower_bound(lis.begin(),lis.end(),x);
            *it = x;
            brr[i]=int(it-lis.begin())+1;
        }
    }
    
    while(Q--){
        int A; cin>>A;
        cout<<arr[A-1]+brr[N-A]-1<<"\n";
    }
    return 0;
}
