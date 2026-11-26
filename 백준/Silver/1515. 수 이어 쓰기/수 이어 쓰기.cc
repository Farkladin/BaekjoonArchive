#include "bits/stdc++.h"
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    queue<char>q;
    string s; cin>>s;
    int n=0;
    for(auto c:s){
        if(q.empty()){
            string cur = to_string(++n);
            for(auto t:cur)q.push(t);
        }
        while(q.front() != c){
            q.pop();
            if(q.empty()){
                string cur=to_string(++n);
                for(auto t:cur)q.push(t);
            }
        }
        q.pop();
    }
    
    cout<<n<<"\n";
    return 0;
}
