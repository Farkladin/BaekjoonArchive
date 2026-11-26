#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
vector<pair<int,string> >vp;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    vp={{0,""}};
    for(int i=1;i<=N;i++){
        string s;cin>>s;
        string cur=vp.back().se;
        if(s=="type"){
            char c;cin>>c;
            int T;cin>>T;
            cur.push_back(c);
            vp.push_back({T,cur});
        }else{
            int t,T;cin>>t>>T;
            auto it=upper_bound(vp.begin(),vp.end(),pair<int,string>(T-t-1,"~"));
            if(it==vp.begin()){
                vp.push_back({T,""});
            }else{
                it--;
                vp.push_back({T,it->se});
            }
        }
    }
    if(!vp.back().se.empty())cout<<vp.back().se<<"\n";
    return 0;
}
