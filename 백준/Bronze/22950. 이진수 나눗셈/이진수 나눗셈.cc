#include "bits/stdc++.h"
#define fi first
#define se second
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
using ppp=pair<pii,pii>;
vector<string>vs;
bool used[503];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N;cin>>N;
    string s;cin>>s;
    int K;cin>>K;
    if(K>=N){
        if(s==string(N,'0')){
            cout<<"YES\n";
        }else cout<<"NO\n";
    }else{
        string t(s.end()-K,s.end());
        cout<<(t==string(t.size(),'0')?"YES\n":"NO\n");
    }
    return 0;
}
