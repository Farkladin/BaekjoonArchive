#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    list<int>ls;
    int N;cin>>N;
    while(N--){
        string s;cin>>s;
        if(s=="push_front"){
            int x;cin>>x;
            ls.push_front(x);
        }else if(s=="push_back"){
            int x;cin>>x;
            ls.push_back(x);
        }else if(s=="pop_front"){
            if(ls.empty())cout<<"-1\n";
            else{
                cout<<ls.front()<<"\n";
                ls.pop_front();
            }
        }else if(s=="pop_back"){
            if(ls.empty())cout<<"-1\n";
            else{
                cout<<ls.back()<<"\n";
                ls.pop_back();
            }
        }else if(s=="size"){
            cout<<ls.size()<<"\n";
        }else if(s=="empty"){
            cout<<ls.empty()<<"\n";
        }else if(s=="front"){
            if(ls.empty())cout<<"-1\n";
            else cout<<ls.front()<<"\n";
        }else if(s=="back"){
            if(ls.empty())cout<<"-1\n";
            else cout<<ls.back()<<"\n";
        }
    }
    return 0;
}
