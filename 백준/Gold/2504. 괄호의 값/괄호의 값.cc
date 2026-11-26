#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    stack<pair<char,ll> >stk;
    stk.push({'!',0});
    string s;cin>>s;
    for(auto c:s){
        if(c=='('){
            stk.push({'(',0});
        }else if(c=='['){
            stk.push({'[',0});
        }else if(c==')'){
            if(stk.top().fi=='('){
                if(stk.top().se==0)stk.top().se++;
                ll tmp=stk.top().se*2;
                stk.pop();
                stk.top().se+=tmp;
            }else{
                cout<<"0\n";
                return 0;
            }
        }else if(c==']'){
            if(stk.top().fi=='['){
                if(stk.top().se==0)stk.top().se++;
                ll tmp=stk.top().se*3;
                stk.pop();
                stk.top().se+=tmp;
            }else{
                cout<<"0\n";
                return 0;
            }
        }
    }
    cout<<(stk.size()==1?stk.top().se:0)<<"\n";
    return 0;
}
