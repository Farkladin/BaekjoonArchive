#include "bits/stdc++.h"
using namespace std;
using ull=uint64_t;
constexpr ull p1=2147483647,p2=2017;
int E[1003];
vector<pair<ull,int> >arr[100003];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    vector<ull>P;
    for(int i=2;i<=1000;i++){
        if(E[i])continue;
        P.push_back(i);
        for(int j=i+i;j<=1000;j+=i)E[j]=1;
    }
    
    string A,B;cin>>A>>B;
    const int N=(int)A.size(),M=(int)B.size();
    
    for(int i=0;i<N;i++){
        ull h1(1),h2(1);
        for(int j=i;j<N;j++){
            h1=h1*P[A[j]-'a']%p1;
            h2=h2*P[A[j]-'a']%p2;
            arr[h2].push_back({h1,j-i+1});
        }
    }
    
    int ans=0;
    for(int i=0;i<M;i++){
        ull h1(1),h2(1);
        for(int j=i;j<M;j++){
            h1=h1*P[B[j]-'a']%p1;
            h2=h2*P[B[j]-'a']%p2;
            for(auto x:arr[h2]){
                if(x.first==h1 && x.second==j-i+1)ans=max(ans,j-i+1);
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}
