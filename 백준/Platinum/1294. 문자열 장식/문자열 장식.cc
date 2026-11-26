#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    priority_queue<string,vector<string>,greater<string> >pq;
    int N;cin>>N;
    while(N--){
        string s;cin>>s;
        s.push_back('~');
        pq.push(s);
    }
    string ans;
    while(!pq.empty()){
        auto x=pq.top();pq.pop();
        ans.push_back(x.front());
        if(x.size()>2)pq.push(string(x.begin()+1,x.end()));
    }
    cout<<ans<<"\n";
    return 0;
}
