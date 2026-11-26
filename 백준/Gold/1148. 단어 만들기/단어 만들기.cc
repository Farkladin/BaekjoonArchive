#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    vector<string>vs;
    vector<array<int,30> >cnt;
    while(1){
        string s;cin>>s;
        if(s=="-")break;
        vs.push_back(s);
        array<int,30>tmp={};
        for(auto c:s)tmp[c-'A']++;
        cnt.push_back(tmp);
    }
    while(1){
        string s;cin>>s;
        if(s=="#")break;
        array<int,30>arr={},brr={};
        for(auto c:s)arr[c-'A']++;
        for(auto v:cnt){
            bool flag=true;
            for(int i=0;i<26;i++){
                flag&=arr[i]>=v[i];
            }
            if(flag){
                for(int i=0;i<26;i++){
                    if(v[i]>0)brr[i]++;
                }
            }
        }

        set<pair<int,char> >sp;
        set<char>a,b;
        int mn=1e9,mx=-1e9;
        for(auto c:s){
            sp.insert({brr[c-'A'],c});
            if(brr[c-'A']<mn){
                mn=brr[c-'A'];
                a.clear();
            }
            if(brr[c-'A']==mn){
                a.insert(c);
            }
            if(brr[c-'A']>mx){
                mx=brr[c-'A'];
                b.clear();
            }
            if(brr[c-'A']==mx){
                b.insert(c);
            }
        }
        for(auto x:a)cout<<x;
        cout<<" "<<mn<<" ";
        for(auto x:b)cout<<x;
        cout<<" "<<mx<<"\n";
    }
    return 0;
}
