#include "bits/stdc++.h"
using namespace std;
int cnt[256];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int T;cin>>T;
    while(T--){
        string s;cin>>s;
        memset(cnt,0,sizeof(cnt));
        for(char c:s)cnt[c]++;
        int W;cin>>W;
        while(W--){
            string t;cin>>t;
            int cur[256]={};
            for(char c:t)cur[c]++;
            bool flag=true;
            for(char c='A';c<='Z';c++){
                flag&=cur[c]<=cnt[c];
            }
            cout<<(flag?"YES\n":"NO\n");
        }
    }
    return 0;
}
