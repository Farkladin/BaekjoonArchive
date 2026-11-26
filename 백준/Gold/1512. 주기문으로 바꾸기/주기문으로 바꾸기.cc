#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
using ull=unsigned long long;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int M;cin>>M;
    string s;cin>>s;
    int n=(int)s.size();
    int ans=1e9;
    for(int k=1;k<=M;k++){
        int cur=0;
        for(int i=0;i<k;i++){
            int a=0,c=0,g=0,t=0;
            for(int j=i;j<n;j+=k){
                if(s[j]=='A')a++;
                else if(s[j]=='C')c++;
                else if(s[j]=='G')g++;
                else if(s[j]=='T')t++;
            }
            cur+=a+c+g+t-max({a,c,g,t});
        }
        ans=min(ans,cur);
    }
    cout<<ans<<"\n";
    return 0;
}
