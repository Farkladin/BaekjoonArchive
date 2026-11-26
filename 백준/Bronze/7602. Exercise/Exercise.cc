#include "bits/stdc++.h"
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int cnt=0;
    while(1){
        int n;cin>>n;
        if(!n)break;
        cout<<"Machine "<<(++cnt)<<"\n";
        vector<int>arr(n);
        for(auto &x:arr)cin>>x;
        while(1){
            string s;int m;cin>>s>>m;
            if(s=="#")break;
            int ans=0;
            while(m--){
                int l,d;cin>>l>>d;
                ans+=arr[l-1]*d;
            }
            cout<<s<<" "<<ans<<"\n";
        }
    }
    return 0;
}
