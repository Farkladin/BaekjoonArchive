#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
using ull=unsigned long long;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    vector<int>X(N),arr(N+N);
    for(int i=0;i<N;i++)cin>>X[i];
    sort(X.begin(),X.end());
    for(int i=0;i<40320;i++){
        fill(arr.begin(),arr.end(),-1);
        int it=0;
        for(auto x:X){
            while(it<N+N&&arr[it]!=-1)it++;
            if(it+x+1<N+N){
                arr[it]=x;
                arr[it+x+1]=x;
            }
        }
        
        for(int i=0;i<N;i++){
            if(arr[i+N]==-1)goto skip;
        }
        
        for(auto a:arr)cout<<a<<" ";
        cout<<"\n";
        return 0;
        
        skip:
        next_permutation(X.begin(),X.end());
    }
    cout<<"-1\n";
    return 0;
}
