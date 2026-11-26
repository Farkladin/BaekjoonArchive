#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
using ull=unsigned long long;
map<pair<pair<char,char>,array<int,52> >,int>mp;
map<string,int>one;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    while(N--){
        string s;cin>>s;
        if(s.size()==1){
            one[s]++;
            continue;
        }
        array<int,52>A={0};
        for(int i=1;i<(int)s.size()-1;i++){
            if(s[i]<='Z')A[s[i]-'A']++;
            else A[s[i]-'a'+26]++;
        }
        mp[{{s.front(),s.back()},A}]++;
    }
    int M;cin>>M;
    cin.ignore();
    while(M--){
        ll ans=1;
        string s;
        getline(cin,s);
        stringstream ss(s);
        while(ss>>s){
            if(s.size()==1){
                ans*=one[s];
                continue;
            }
            array<int,52>A={0};
            for(int i=1;i<(int)s.size()-1;i++){
                if(s[i]<='Z')A[s[i]-'A']++;
                else A[s[i]-'a'+26]++;
            }
            ans*=mp[{{s.front(),s.back()},A}];
        }
        cout<<ans<<"\n";
    }
    return 0;
}
