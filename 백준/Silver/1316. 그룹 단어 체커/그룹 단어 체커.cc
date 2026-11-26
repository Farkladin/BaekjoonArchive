#include "bits/stdc++.h"
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int ans=0;
    int N; cin>>N;
    while(N--){
        string s;cin>>s;
        vector<int>count(256);
        ++count[s[0]];
        for(int i=1; i<(int)s.size(); ++i){
            if(s[i-1] != s[i]){
                ++count[s[i]];
            }
        }
        
        int x=1;
        for(int i='a'; i<='z'; ++i){
            x&=(count[i]<=1);
        }
        if(x)++ans;
    }
    cout<<ans<<"\n";
    
    return 0;
}
