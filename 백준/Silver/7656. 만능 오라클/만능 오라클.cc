#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    string input;
    getline(cin,input);
    stringstream ss(input);
    string s,t;
    while(ss>>s){
        if(s=="What"&&t.empty()){
            t="Forty-two";
        }else if(!t.empty()){
            if(t=="Forty-two"&&string(s.begin(),s.begin()+2)!="is"){
                t.clear();
                continue;
            }
            t+=" "+s;
        }
        if(!t.empty()&&t.back()=='.'){
            t.clear();
        }
        if(!t.empty()&&t.back()=='?'){
            t.pop_back();
            cout<<t<<".\n";
            t.clear();
        }
    }
    return 0;
}
