#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;

string peter[5]={
    "..#..",
    ".#.#.",
    "#.@.#",
    ".#.#.",
    "..#.."
};
string wendy[5]={
    "..*..",
    ".*.*.",
    "*.@.*",
    ".*.*.",
    "..*.."
};

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    string s;cin>>s;
    int cnt=0;
    string ans[5];
    for(char c:s){
        cnt++;
        if(cnt==3){
            cnt=0;
            wendy[2][2]=c;
            for(int i=0;i<5;i++){
                ans[i].pop_back();
                ans[i]+=wendy[i];
            }
        }else{
            peter[2][2]=c;
            for(int i=0;i<5;i++){
                if(ans[i].empty())ans[i]+=peter[i];
                else ans[i]+=string(peter[i].begin()+1,peter[i].end());
            }
        }
    }
    for(int i=0;i<5;i++){
        cout<<ans[i]<<"\n";
    }
    return 0;
}
