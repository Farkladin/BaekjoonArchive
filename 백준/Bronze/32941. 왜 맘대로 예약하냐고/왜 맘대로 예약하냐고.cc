#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int T,X;cin>>T>>X;
    int N;cin>>N;
    bool flag=true;
    while(N--){
        int K;cin>>K;
        int cnt=0;
        while(K--){
            int A;cin>>A;
            if(A==X)cnt++;
        }
        flag&=cnt>0;
    }
    cout<<(flag?"YES\n":"NO\n");
    return 0;
}
