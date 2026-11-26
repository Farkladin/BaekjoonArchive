#include "bits/stdc++.h"
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int T;cin>>T;
    while(T--){
        int n;cin>>n;
        vector<string>vs(n);
        vector<int>idx(n);
        for(auto &s:vs)cin>>s;
        for(int i=0;i<n;i++){
            string s;cin>>s;
            for(int j=0;j<n;j++){
                if(s==vs[j]){
                    idx[i]=j;
                    break;
                }
            }
        }
        vector<string>ans(n);
        for(int i=0;i<n;i++){
            cin>>ans[idx[i]];
        }
        for(auto &s:ans)cout<<s<<" ";
        cout<<"\n";
    }
    return 0;
}
