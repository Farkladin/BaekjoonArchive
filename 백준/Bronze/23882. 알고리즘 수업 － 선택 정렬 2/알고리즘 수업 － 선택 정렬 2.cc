#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N,K;cin>>N>>K;
    vector<int>A(N+3);
    auto cmp=[&A](const int &a,const int &b)->bool{
        return A[a]>A[b];
    };
    set<int,decltype(cmp)>sp(cmp);
    for(int i=1;i<=N;i++){
        cin>>A[i];
        sp.insert(i);
    }
    int cnt=0;
    for(int i=N;i>1;i--){
        int j=*sp.begin();
        sp.erase(i);
        if(j!=i){
            sp.erase(sp.begin());
            swap(A[i],A[j]);
            sp.insert(j);
            cnt++;
        }
        if(cnt==K){
            for(int j=1;j<=N;j++)cout<<A[j]<<" ";
            cout<<"\n";
            return 0;
        }
    }
    cout<<"-1\n";
    return 0;
}
