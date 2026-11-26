#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int T;cin>>T;
    for(int tc=1;tc<=T;tc++){
        cout<<"Case #"<<tc<<": ";
        int N;cin>>N;
        cin.ignore();
        vector<string>vs(N+2);
        for(int i=1;i<=N;i++){
            getline(cin,vs[i]);
        }
        string_view mx=vs[1];
        int cnt=0;
        for(int i=2;i<=N;i++){
            if(mx>vs[i]){
                cnt++;
            }
            mx=max(mx,(string_view)vs[i]);
        }
        cout<<cnt<<"\n";
    }
    return 0;
}
