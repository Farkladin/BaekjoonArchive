#include "bits/stdc++.h"
using namespace std;

int brr[100003], init[100003];
int fin[100003];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int N,M; cin>>N>>M;
    vector<vector<int> > arr(M);
    
    for(auto &vec:arr){
        int k; cin>>k;
        vec.reserve(k);
        while(k--){
            int a; cin>>a;
            vec.push_back(a);
        }
    }
    
    for(int i=1; i<=N; ++i){
        cin>>fin[i];
        brr[i] = fin[i];
    }
    
    reverse(arr.begin(), arr.end());
    for(auto &vec:arr){
        int flag=0;
        for(auto x:vec) flag |= !brr[x];
        if(flag){
            for(auto x:vec) brr[x]=0;
        }
    }
    for(int i=1; i<=N; ++i) init[i]=brr[i];
    
    reverse(arr.begin(), arr.end());
    for(auto &vec:arr){
        int flag=0;
        for(auto x:vec) flag |= brr[x];
        if(flag){
            for(auto x:vec) brr[x]=1;
        }
    }
    
    
    bool ans=true;
    for(int i=1; i<=N; ++i){
        ans &= fin[i]==brr[i];
    }
    if(!ans){
        cout<<"NO\n";
    }else{
        cout<<"YES\n";
        for(int i=1; i<=N; ++i) cout<<init[i]<<" ";
        cout<<"\n";
    }
    
    return 0;
}
