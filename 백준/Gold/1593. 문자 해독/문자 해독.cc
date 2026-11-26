#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int cnt[256],W[256];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int g,n;cin>>g>>n;
    for(int i=0;i<g;i++){
        char c;cin>>c;
        W[c]++;
    }
    string S;cin>>S;
    for(int i=0;i<g;i++){
        cnt[S[i]]++;
    }
    int ans=1;
    for(int j=0;j<256;j++){
        if(cnt[j]!=W[j])ans=0;
    }
    for(int i=g;i<n;i++){
        cnt[S[i]]++;
        cnt[S[i-g]]--;
        int cur=1;
        for(int j='a';j<='z';j++)cur&=cnt[j]==W[j];
        for(int j='A';j<='Z';j++)cur&=cnt[j]==W[j];
        ans+=cur;
    }
    cout<<ans<<"\n";
    return 0;
}
