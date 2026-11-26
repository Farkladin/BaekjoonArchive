#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
vector<int>A,B;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    string S,T;cin>>S>>T;
    const int n=(int)S.size(),m=(int)T.size();
    A.resize(m+3);
    B.resize(m+3);
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            B[j]=max({A[j],B[j-1],A[j-1]+(S[i-1]==T[j-1])});
            ans=max(ans,B[j]);
        }
        A=B;
    }
    cout<<ans<<"\n";
    return 0;
}
