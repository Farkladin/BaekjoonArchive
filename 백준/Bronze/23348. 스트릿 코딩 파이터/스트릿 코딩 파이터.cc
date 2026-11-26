#include "bits/stdc++.h"
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int A,B,C;cin>>A>>B>>C;
    int N;cin>>N;
    
    int mx=0;
    while(N--){
        int cur=0;
        for(int i=0;i<3;i++){
            int a,b,c;cin>>a>>b>>c;
            cur+=a*A+b*B+c*C;
        }
        mx=max(mx,cur);
    }
    cout<<mx<<"\n";
    return 0;
}
